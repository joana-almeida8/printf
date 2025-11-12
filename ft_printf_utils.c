/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:29:54 by jreis-de          #+#    #+#             */
/*   Updated: 2025/11/12 14:51:42 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_adress_pf(unsigned long n, int base)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr_pf("(nil)"));
	count += ft_putstr_pf("0x");
	if (n < (unsigned long)base)
		return (ft_putchar_pf(hexa[n]));
	else
		count = ft_putnbr_base_pf(n / base, base);
	count += ft_putnbr_base_pf(n % base, base);
	return (count + 2);
}

int	ft_putnbr_base_pf(long n, int base)
{
	char	*hexa;
	int		count;

	hexa = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar_pf('-');
		return (ft_putnbr_base_pf(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar_pf(hexa[n]));
	else
		count = ft_putnbr_base_pf(n / base, base);
	count += ft_putnbr_base_pf(n % base, base);
	return (count);
}

int	ft_putnbr_base_upper_pf(long n, int base)
{
	char	*hexa;
	int		count;

	hexa = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar_pf('-');
		return (ft_putnbr_base_upper_pf(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar_pf(hexa[n]));
	else
		count = ft_putnbr_base_upper_pf(n / base, base);
	count += ft_putnbr_base_upper_pf(n % base, base);
	return (count);
}

int	ft_putnbr_unsigned_pf(unsigned long n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}
