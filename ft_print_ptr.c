/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:23:48 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/18 01:54:29 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	len += ft_print_hex((unsigned long)ptr, 'x');
	return (len);
}
