/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:53 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 18:35:31 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
#include <unistd.h>
int main()
{
	char str = 'c';
	int i =	ft_printf("hello %c", str);
	printf("%d\n\n\n", i);
	int k = printf("hello %c", str);
	printf("%d\n", k);
}