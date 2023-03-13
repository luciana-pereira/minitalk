/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:45:19 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/18 02:27:25 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEX "0123456789abcdef"

int		print_pointer(unsigned long int n);
int		ft_printf(const char *str, ...);
int		verify(char str, va_list *args);
int		print_char(char c);
int		print_str(char *str);
int		ptr_to_hex(int c);
int		print_uns(unsigned int c);
int		print_hex(unsigned int n, int c);
int		ft_putchar(char c);
void	ptr_hex(int p);
size_t	ft_strlen(const char *s);

#endif