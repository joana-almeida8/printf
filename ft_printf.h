/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:42:33 by jreis-de          #+#    #+#             */
/*   Updated: 2025/11/09 18:42:33 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_address_pf(unsigned long n, int base);
int	ft_putnbr_base_pf(long n, int base);
int	ft_putnbr_base_upper_pf(long n, int base);
int	ft_putnbr_unsigned_pf(unsigned long n);

#endif
