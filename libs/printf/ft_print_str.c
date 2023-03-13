/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:42:51 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/18 02:14:43 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		len += write(1, str++, 1);
	}
	return (len);
}
