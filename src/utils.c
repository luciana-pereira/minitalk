/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:06:36 by lucperei          #+#    #+#             */
/*   Updated: 2023/03/13 03:44:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	send_null(int pid, char *message)
{
	static int	index = 0;

	if (index++ != BIT)
	{
		if (kill(pid, SIGUSR1) == SIG_ERROR)
			send_error(message, pid, SIGUSR1);
		return (0);
	}
	return (1);
}

void	handler_sig(int sig)
{
	int	letter;

	letter = 0;
	if (sig == SIGUSR1)
		letter = send_message(0, NULL);
	else if (sig == SIGUSR2)
	{
		ft_printf("Error: Server ended unexpectdly.\n");
		exit(EXIT_FAILURE);
	}
	if (letter)
	{
		ft_printf("Info: Message received successfully.\n");
		exit(EXIT_SUCCESS);
	}
}
