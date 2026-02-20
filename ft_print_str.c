/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:42:17 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/19 15:49:36 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
