/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:18:39 by lucperei          #+#    #+#             */
/*   Updated: 2023/03/13 03:58:48 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/minitalk_bonus.h"

int	send_message(int pid, char *str)
{
	static char	*message = NULL;
	static int	s_pid = 0;
	static int	bits = 0;

	if (str)
		message = ft_strdup(str);
	if (!message)
		send_error(NULL, 0, 0);
	if (pid)
		s_pid = pid;
	if (message[bits / BIT])
	{
		if (message[bits / BIT] & (MAX_RANGE >> (bits % BIT)))
		{
			if (kill(s_pid, SIGUSR2) == SIG_ERROR)
				send_error(message, s_pid, SIGUSR2);
		}
		else if (kill(s_pid, SIGUSR1) == SIG_ERROR)
			send_error(message, s_pid, SIGUSR1);
		bits++;
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	return (free (message), 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Incorrect number of arguments!\n");
		ft_printf("Try: %s <PID> \"<MESSAGE>\"\n", argv[0]);
		exit(1);
	}
	signal(SIGUSR1, &handler_sig);
	signal(SIGUSR2, &handler_sig);
	if (!ft_atoi(argv[1]))
	{
		ft_printf("Error: %s is an invalid PID\n", argv[1]);
		exit(1);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
