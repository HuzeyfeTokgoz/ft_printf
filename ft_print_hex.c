/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:40:54 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 20:53:25 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex(unsigned int nb, const char format)
{
	char	*digit;
	int		len;
	
	if (format == 'x')
		digit = "0123456789abcdef";
	else 
		digit = "0123456789ABCDEF";
	len = 0;
	if (nb >= 16)
		len += ft_print_hex(nb / 16, format);
	len += ft_print_char(digit[nb % 16]);
	return (len);
}