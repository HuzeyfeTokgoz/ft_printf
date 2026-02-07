/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:53 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 22:40:46 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	print_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			len += print_format(str[i], args);
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
