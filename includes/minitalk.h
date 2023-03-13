/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:56:22 by lucperei          #+#    #+#             */
/*   Updated: 2023/03/13 03:43:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libs/printf/ft_printf.h"
# include "../libs/libft/libft.h"

# define BIT 8
# define MAX_RANGE 128
# define SIG_ERROR -1

void	send_error(char *message, int pid, int sig);
void	handler_sig(int sig);
int		send_message(int pid, char *str);
int		send_null(int pid, char *message);

#endif
