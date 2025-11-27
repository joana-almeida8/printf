/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:29:54 by jreis-de          #+#    #+#             */
/*   Updated: 2025/11/27 10:25:08 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_address_pf(unsigned long n, int base)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr_pf("(nil)"));
	count += ft_putstr_pf("0x");
	if (n < (unsigned long)base)
		count += ft_putchar_pf(hexa[n]);
	else
	{
		count += ft_putnbr_base_pf(n / base, base);
		count += ft_putnbr_base_pf(n % base, base);
	}
	return (count);
}

int	ft_putnbr_base_pf(long n, int base)
{
	char	*hexa;
	int		count;

	hexa = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		count += ft_putnbr_base_pf(-n, base);
	}
	else if (n < base)
		count += ft_putchar_pf(hexa[n]);
	else
	{
		count += ft_putnbr_base_pf(n / base, base);
		count += ft_putnbr_base_pf(n % base, base);
	}
	return (count);
}

int	ft_putnbr_base_upper_pf(long n, int base)
{
	char	*hexa;
	int		count;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		count += ft_putnbr_base_upper_pf(-n, base);
	}
	else if (n < base)
		count += ft_putchar_pf(hexa[n]);
	else
	{
		count += ft_putnbr_base_upper_pf(n / base, base);
		count += ft_putnbr_base_upper_pf(n % base, base);
	}
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
