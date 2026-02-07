/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:10:49 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 17:22:22 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>

int	ft_print_char(char c)
{
	if (!c)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	write(1,&c,1);
	return (1);
}