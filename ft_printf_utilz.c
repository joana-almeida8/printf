/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:02:06 by jreis-de          #+#    #+#             */
/*   Updated: 2025/11/12 14:32:49 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_pf(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr_pf("(nil)"));
	while (str[i])
	{
		ft_putchar_pf((int)str[i]);
		i++;
	}
	return (i);
}