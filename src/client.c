/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:10:43 by lucperei          #+#    #+#             */
/*   Updated: 2023/03/08 03:35:19 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
	if (message[bits / 8])
	{
		if (message[bits / 8] & (128 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				send_error(message, pid, SIGUSR2);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			send_error(message, pid, SIGUSR1);
		bits++;
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	return (free (message), 1);
}

int	main(int argc, char **argv)
{
	if ((argc != 3))
	{
		ft_printf("Error: Incorrect number of arguments!\n");
		ft_printf("Try: %s <PID> \"<MESSAGE>\"\n", argv[0]);
		exit(1);
	}
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);
	if (!ft_atoi(argv[1]))
	{
		ft_printf("Error: %s is an invalid PID\n", argv[1]);
		exit(1);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
