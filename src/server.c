/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:11:16 by lucperei          #+#    #+#             */
/*   Updated: 2023/03/13 03:44:05 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum, siginfo_t *s_info, void *context)
{
	static int		dec = 255;
	static int		bits = 0;
	static int		pid = 0;

	(void)context;
	pid = s_info->si_pid;
	if (signum == SIGUSR1)
		dec ^= (MAX_RANGE >> bits);
	else if (signum == SIGUSR2)
		dec |= (MAX_RANGE >> bits);
	if (++bits == BIT)
	{
		if (dec)
			ft_printf("%c", dec);
		else
			ft_printf("\n");
		bits = 0;
		dec = 255;
	}
	if (kill(pid, SIGUSR1) == SIG_ERROR)
	{
		kill(pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa_sig;

	sigemptyset(&sa_sig.sa_mask);
	sigaddset(&sa_sig.sa_mask, SIGINT);
	sigaddset(&sa_sig.sa_mask, SIGQUIT);
	sa_sig.sa_handler = 0;
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}
