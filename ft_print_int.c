/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:42:48 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 21:06:09 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(int n)
{
	int	i;
	long nb;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += ft_print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		i += ft_print_int(nb / 10);
	i += ft_print_char((nb % 10) + '0');
	return (i);
}