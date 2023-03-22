/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:18:30 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/18 02:08:34 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	while ((s[a] == '\t' || s[a] == '\f' || s[a] == '\n'
			|| s[a] == '\v' || s[a] == '\r') || s[a] == ' ')
	{
		a++;
	}
	if (s[a] == '+' || s[a] == '-')
	{
		if (s[a] == '-')
			b = -1;
		a++;
	}
	while (s[a] >= '0' && s[a] <= '9')
	{
		c = (s[a] - '0') + (c * 10);
		a++;
	}
	return (c * b);
}