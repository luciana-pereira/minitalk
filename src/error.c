/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:27:40 by lucperei          #+#    #+#             */
/*   Updated: 2023/03/12 17:07:41 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_error(char *message, int pid, int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Error: Sending SIGUSR1 signal to PID %i failed\n", pid);
	else if (sig == SIGUSR2)
		ft_printf("Error: Sending SIGUSR2 signal to PID %i failed\n", pid);
	else
		ft_printf("Error: Sending unknown signal to PID %i\n", pid);
	if (message)
	{
		free(message);
	}
	exit(EXIT_FAILURE);
}
