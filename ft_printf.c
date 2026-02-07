/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:53 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 21:17:04 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int ft_printf(const char *str, ...)
{
	int	len;
	int i = 0;
	len = 0;
	va_list args;
	
	va_start(args, str);
	
	while (str[i])
	{	
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break;
			if (str[i] == 's')
				len += ft_print_str(va_arg(args, char *));
			else if (str[i] == 'c')
				len += ft_print_char(va_arg(args, int)); // char inte dönüştürülur derleyici arkada bunu yapar sen char istesen bile en az intlik boyutta taşınır (işlemci mimarisi stack için)
			else if (str[i] == 'd' || str[i] == 'i')
				len += ft_print_int(va_arg(args, int));
			else if (str[i] == 'u')
				len += ft_print_unsigned(va_arg(args, unsigned int));
			else if (str[i] == 'p')
				len += ft_print_ptr(va_arg(args, void *));
			else if (str[i] == 'x' || str[i] == 'X')
				len += ft_print_hex(va_arg(args, unsigned int), str[i]);
			else if (str[i] == '%')
				len += ft_print_char('%');
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
int main()
{
	unsigned int str = 1243;
	int i =	ft_printf("hello %X\n", str);
	printf("%d\n\n\n", i);

	int k = printf("hello %X\n", str);
	printf("%d\n", k);
}