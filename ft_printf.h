/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:49 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/07 21:16:54 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(int n);
int ft_print_unsigned(unsigned int nb);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(unsigned int nb, char format);

# endif