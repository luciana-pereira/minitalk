/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:44:36 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/18 03:02:41 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	verify(char str, va_list *args)
{
	int	len;

	len = 0;
	if (str == '\0')
	{
		return (0);
	}
	else if (str == 'c')
		len += print_char(va_arg(*args, int));
	else if (str == 's')
		len += print_str(va_arg(*args, char *));
	else if (str == 'p')
		len += print_pointer(va_arg(*args, unsigned long int));
	else if (str == 'd' || str == 'i')
		len += ptr_to_hex(va_arg(*args, int));
	else if (str == 'u')
		len += print_uns(va_arg(*args, unsigned int));
	else if (str == 'x')
		len += print_hex(va_arg(*args, unsigned int), 1);
	else if (str == 'X')
		len += print_hex(va_arg(*args, unsigned int), 2);
	else if (str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;
	int		index;

	len = 0;
	index = 0;
	va_start(ptr, str);
	while (str[index] != '\0')
	{
		if (str[index] != '%')
		{
			len += write(1, &str[index], 1);
		}
		if (str[index] == '%')
		{
			len += verify(str[index + 1], &ptr);
			index++;
		}
		index++;
	}
	va_end(ptr);
	return (len);
}
