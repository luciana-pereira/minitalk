/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:43:33 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/18 02:16:45 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uns(unsigned int c)
{
	int	len;

	len = 0;
	if (c >= 10)
	{
		len += print_uns(c / 10);
		len += print_uns(c % 10);
	}
	if (c < 10)
	{
		len += print_char(c + 48);
	}
	return (len);
}
