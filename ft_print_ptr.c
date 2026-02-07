/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:23:48 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 22:12:18 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long addr)
{
	int		len;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	len = 0;
	if (addr >= 16)
		len += ft_put_hex(addr / 16);
	len += ft_print_char(hex_digits[addr % 16]);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		ft_print_str("(nil)");
		return (5);
	}
	len += ft_print_str("0x");
	len += ft_put_hex((unsigned long)ptr);
	return (len);
}
