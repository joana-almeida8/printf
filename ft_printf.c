/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:42:39 by jreis-de          #+#    #+#             */
/*   Updated: 2025/11/09 18:42:39 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_check(va_list var, char *str)
{
	int	count;

	if (*str == 'c')
		count = ft_putchar_pf(va_arg (var, int));
	else if (*str == 's')
		count = ft_putstr_pf(va_arg (var, char *));
	else if (*str == 'p')
		count = ft_putnbr_address_pf((unsigned long)va_arg (var, void *), 16);
	else if (*str == 'd' || *str == 'i')
		count = ft_putnbr_base_pf((long)va_arg (var, int), 10);
	else if (*str == 'u')
		count = ft_putnbr_unsigned_pf(va_arg (var, unsigned int));
	else if (*str == 'x')
		count = ft_putnbr_base_pf((long)va_arg (var, unsigned int), 16);
	else if (*str == 'X')
		count = ft_putnbr_base_upper_pf((long)va_arg (var, unsigned int), 16);
	else if (*str == '%')
		count = ft_putchar_pf('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	var;
	int		res;

	if (!format)
		return (-1);
	count = 0;
	va_start(var, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			res = ft_format_check(var, (char *)format);
			if (res == -1)
				return (-1);
			count += res;
		}
		else
			count += ft_putchar_pf(*format);
		format++;
	}
	va_end (var);
	return (count);
}
