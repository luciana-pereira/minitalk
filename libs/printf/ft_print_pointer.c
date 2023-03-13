/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:41:50 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/18 02:54:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_to_hex(int c)
{
	long long	n;
	int			len;

	n = c;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		len += ptr_to_hex(n / 10);
		len += ptr_to_hex(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}

static int	len_hex(unsigned long int n)
{
	unsigned long int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*hex_to_str(unsigned long int n, char *base)
{
	char	*hex;
	int		size;

	size = len_hex(n);
	hex = (char *)malloc(size + 1);
	if (!hex)
		return (NULL);
	hex[size--] = '\0';
	while (n > 0)
	{
		hex[size--] = base[n % 16];
		n /= 16;
	}
	if (size == 0 && hex[1] == '\0')
		hex[0] = 48;
	return (hex);
}

int	print_pointer(unsigned long int n)
{
	int		len;
	char	*str;

	len = 0;
	if (!n)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
	{
		len += write(1, "0x", 2);
		str = hex_to_str(n, HEX);
	}
	len += write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
