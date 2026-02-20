/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:53 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/20 22:45:52 by hutokgoz         ###   ########.fr       */
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
	else if (c != '\0')
		len += ft_print_char('%') + ft_print_char(c);
	return (len);
}

int	ft_print_form(const char *str, va_list args, int check, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			check = print_format(str[i], args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			check = ft_print_char(str[i]);
			if (check == -1)
				return (-1);
			len += check;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		check;
	va_list	args;

	len = 0;
	check = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	len = ft_print_form(str, args, check, len);
	va_end(args);
	return (len);
}
