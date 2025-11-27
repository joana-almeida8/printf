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

/* int main(void)
{
    int count;
    char c = 'a';
    char str[] = "Ducklings";
    int nb = -4273644;

    count = ft_printf("%s e uma string e %d e um numero decimal\n", str, nb);
    ft_printf("ft_printf: %d\n", count);
    printf("printf: %d\n", count);
    return (0);
} */

/* int main(void)
{
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Pointer: %p\n", NULL);
    ft_printf("Pointer: %p\n", (void *)0x1234abcd);
    ft_printf("Decimal: %d\n", -12345);
    ft_printf("Unsigned: %u\n", 4294967295u);
    ft_printf("Hex lower: %x\n", 255);
    ft_printf("Hex upper: %X\n", 255);
    ft_printf("Percent: %%\n");
    return 0;
} */

/*#include <stdio.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int	index;
	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_putnbr(int nbr)
{
	char	c;
	int		count;

	count = 0;
	if (nbr / 10 == 0)
	{
		if (nbr < 0)
		{
			count += write(1, "-", 1);
			nbr = -nbr;
		}
		c = nbr + '0';
		count += write(1, &c, 1);
		return (count);
	}
	count += ft_putnbr(nbr / 10);
	if (nbr < 0)
		c = '0' + -(nbr % 10);
	else
		c = '0' + (nbr % 10);
	return (count + write(1, &c, 1));
}

void	test_characters()
{
	printf("\n");
	
	printf("|--------------------------------------------------------|\n");
	printf("|                     Tests Char %%c                      |\n");
	printf("|--------------------------------------------------------|\n\n");

	char	tc;
	int		tc_v;
	int		count;
	int		index;

	tc_v = 97;
	tc = tc_v;
	index = 1;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = 48;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = -128;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = 127;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = 128;
	tc = tc_v;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = 254;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = 255;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = -129;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = 256;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	tc_v = -927;
	tc = tc_v;
	index++;

	printf(" Test %d: Real Value: %d | ASCII: %d (%c)\n", index, tc_v, tc, tc);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c", tc);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c", tc);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	char tc1 = 'O';
	char tc2 = 'l';
	char tc3 = 'a';
	index++;

	printf(" Test %d: Ola | ASCII codes: %d, %d, %d\n",index, tc1, tc2, tc3);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c%c%c", tc1, tc2, tc3);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c%c%c", tc1, tc2, tc3);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                     Tests Char %%c                      |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_strings()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Strings %%s                    |\n");
	printf("|--------------------------------------------------------|\n\n");
	
	char	*ts;
	int		count;
	int		index;
	ts = "Ola";
	index = 1;

	printf(" Test %d: String: %s (%d)\n", index, ts, ft_strlen(ts));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%s", ts);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%s", ts);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	ts = "Ola Mundo";
	index++;

	printf(" Test %d: String: %s (%d)\n", index, ts, ft_strlen(ts));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%s", ts);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%s", ts);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	char *ts1 = "Ola";
	char *ts2 = " Mundo";
	char *ts3 = " 42!";
	index++;

	printf(" Test %d: Strings: %s (%d) | %s (%d) | %s (%d)\n",
		index, ts1, ft_strlen(ts1), ts2, ft_strlen(ts2), ts3, ft_strlen(ts3));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%s%s%s", ts1, ts2, ts3);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%s%s%s", ts1, ts2, ts3);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	ts = "\255\024\200\177\055\099\045";
	index++;

	printf(" Test %d: String: %s (%d)\n", index, ts, ft_strlen(ts1));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%s", ts);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%s", ts);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);

	
	ts = NULL;
	index++;

	printf(" Test %d: String: %s (%d)\n", index, ts, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%s", ts);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%s", ts);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Strings %%s                    |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_pointers()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                   Tests Pointers %%p                    |\n");
	printf("|--------------------------------------------------------|\n\n");

	int		count;
	int		index;
	
	char	c = 'a';
	char	*ptr_c = &c;
	index = 1;

	printf(" Test %d: Pointer Char: ptr_c (%lu)\n", index, sizeof(ptr_c));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%p", ptr_c);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p", ptr_c);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	char	*s = "Ola Mundo";
	index++;
	
	printf(" Test %d: String: %s (%lu)\n", index, s, sizeof(s));
	fflush(stdout);
	
	write(1, "   printf    -> ", 16);
	count = printf("%p", s);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);
	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p", s);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	int		i = 42;
	int		*ptr_i = &i;
	index++;

	printf(" Test %d: Pointer Int: ptr_i (%lu)\n", index, sizeof(ptr_i));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%p", ptr_i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p", ptr_i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	void	*ptr_v1 = &ptr_c;
	index++;

	printf(" Test %d: Pointer Void: ptr_v1 (%lu)\n", index, sizeof(ptr_v1));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%p", ptr_v1);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p", ptr_v1);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	void	*ptr_v2 = &ptr_i;
	index++;

	printf(" Test %d: Pointer Void: ptr_v2 (%lu)\n", index, sizeof(ptr_v2));
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%p", ptr_v2);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p", ptr_v2);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	void	*ptr_v3 = NULL;
	index++;

	printf(" Test %d: Pointer Void: NULL (%i)\n", index, 5);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%p", ptr_v3);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p", ptr_v3);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);

	printf("|--------------------------------------------------------|\n");
	printf("|                   Tests Pointers %%p                    |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_integer_d()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Integer %%d                    |\n");
	printf("|--------------------------------------------------------|\n\n");

	int	i;
	int	count;
	int	index;

	i = 0;
	index = 1;

	printf(" Test %d: Integer (d): %d (%d)\n", index, i, 1);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = 42;
	index++;

	printf(" Test %d: Integer (d): %d (%d)\n", index, i, 2);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = INT_MAX;
	index++;

	printf(" Test %d: Integer (d): %d (%d)\n", index, i, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = INT_MIN;
	index++;

	printf(" Test %d: Integer (d): %d (%d)\n", index, i, 11);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = 02534;
	index++;

	printf(" Test %d: Integer Octal (d): 02534 > %d (%d)\n", index, i, 4);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = 0xF4B3;
	index++;

	printf(" Test %d: Integer Hexa (d): 0xF4B3 > %d (%d)\n", index, i, 5);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = -037321;
	index++;

	printf(" Test %d: Integer Octal (d): -037321 > %d (%d)\n", index, i, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = -0xFF0A;
	index++;

	printf(" Test %d: Integer Hexa (d): -0xFF0A > %d (%d)\n", index, i, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%d", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%d", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Integer %%d                    |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_integer_i()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Integer %%i                    |\n");
	printf("|--------------------------------------------------------|\n\n");

	int	i;
	int	count;
	int	index;

	i = 0;
	index = 1;

	printf(" Test %d: Integer (i): %i (%d)\n", index, i, 1);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = 42;
	index++;

	printf(" Test %d: Integer (i): %i (%d)\n", index, i, 2);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = INT_MAX;
	index++;

	printf(" Test %d: Integer (i): %i (%d)\n", index, i, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = INT_MIN;
	index++;

	printf(" Test %d: Integer (i): %i (%d)\n", index, i, 11);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = 02534;
	index++;

	printf(" Test %d: Integer Octal (i): 02534 > %i (%d)\n", index, i, 4);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = 0xF4B3;
	index++;

	printf(" Test %d: Integer Octal (i): 0xF4B3 > %i (%d)\n", index, i, 5);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = -037321;
	index++;

	printf(" Test %d: Integer Octal (d): -037321 > %i (%d)\n", index, i, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	i = -0xFF0A;
	index++;

	printf(" Test %d: Integer Hexa (d): -0xFF0A > %i (%d)\n", index, i, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%i", i);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%i", i);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Integer %%i                    |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_unsigned_integer()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                Tests Unsigned Integer %%u               |\n");
	printf("|--------------------------------------------------------|\n\n");

	unsigned int	u;
	int				count;
	int				index;

	u = 0;
	index = 1;

	printf(" Test %d: Unsigned Integer: %u (%d)\n", index, u, 1);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	u = INT_MAX;
	index++;

	printf(" Test %d: Unsigned Integer: %u (%d)\n", index, u, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	u = INT_MIN;
	index++;

	printf(" Test %d: Unsigned Integer: %i (%d)\n", index, u, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	u = UINT_MAX;
	index++;

	printf(" Test %d: Unsigned Integer: %i (%d)\n", index, u, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	u = 02534;
	index++;

	printf(" Test %d: Unsigned Integer Octal: 02534 > %u (%d)\n", index, u, 4);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	u = 0xF4B3;
	index++;

	printf(" Test %d: Unsigned Integer Hexa: 0xF4B3 > %u (%d)\n", index, u, 5);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);
	

	u = -037321;
	index++;

	printf(" Test %d: Integer Octal: -037321 > %u (%d)\n", index, u, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	u = -0xFF0A;
	index++;

	printf(" Test %d: Integer Hexa (d): -0xFF0A > %u (%d)\n", index, u, 10);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%u", u);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%u", u);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                Tests Unsigned Integer %%u               |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_hexa_lower()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                  Tests Hexadecimal %%x                  |\n");
	printf("|--------------------------------------------------------|\n\n");

	unsigned int	x;
	int				count;
	int				index;

	x = 0;
	index = 1;

	printf(" Test %d: Hexa (h): %x (%d)\n", index, x, 1);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = 42;
	index++;

	printf(" Test %d: Hexa (h): %x (%d)\n", index, x, 2);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = INT_MAX;
	index++;

	printf(" Test %d: Hexa (h): %x (%d)\n", index, x, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = UINT_MAX;
	index++;

	printf(" Test %d: Hexa (h): %x (%d)\n", index, x, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = INT_MIN;
	index++;

	printf(" Test %d: Hexa (h): %x (%d)\n", index, x, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);

	
	x = 0xF12321F;
	index++;

	printf(" Test %d: Hexa (h): 0xF12321F (%d)\n", index, 7);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);

	
	x = 07723723;
	index++;

	printf(" Test %d: Hexa (h): 07723723 > %x (%d)\n", index, x, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                  Tests Hexadecimal %%x                  |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_hexa_upper()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                  Tests Hexadecimal %%X                  |\n");
	printf("|--------------------------------------------------------|\n\n");

	unsigned int	x;
	int				count;
	int				index;

	x = 0;
	index = 1;

	printf(" Test %d: Hexa (h): %X (%d)\n", index, x, 1);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = 42;
	index++;

	printf(" Test %d: Hexa (h): %X (%d)\n", index, x, 2);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = INT_MAX;
	index++;

	printf(" Test %d: Hexa (h): %X (%d)\n", index, x, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = UINT_MAX;
	index++;

	printf(" Test %d: Hexa (h): %X (%d)\n", index, x, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	x = INT_MIN;
	index++;

	printf(" Test %d: Hexa (h): %X (%d)\n", index, x, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);

	
	x = 0xf12321f;
	index++;

	printf(" Test %d: Hexa (h): 0xf12321f (%d)\n", index, 7);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);

	
	x = 07723723;
	index++;

	printf(" Test %d: Hexa (h): 07723723 > %X (%d)\n", index, x, 6);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%X", x);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%X", x);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                  Tests Hexadecimal %%X                  |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_percent()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Percentage %%                  |\n");
	printf("|--------------------------------------------------------|\n");
	
	int	count;
	int	index;
	index = 1;

	printf(" Test %d: %d Percents (%d)\n", index, index, index);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%%");
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%%");
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	index++;

	printf(" Test %d: %d Percents (%d)\n", index, index, index);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%%%%");
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%%%%");
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	index++;

	printf(" Test %d: %d Percents (%d)\n", index, 8, 8);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%%%%%%%%%%%%%%%%");
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%%%%%%%%%%%%%%%%");
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|                    Tests Percentage %%                  |\n");
	printf("|--------------------------------------------------------|\n");
}

void	test_multiple()
{
	printf("|--------------------------------------------------------|\n");
	printf("|               Tests Multiple Conversions               |\n");
	printf("|--------------------------------------------------------|\n\n");

	int		index = 1;
	int		count;
	
	char	tc1 = 'A';
	int		ti1 = 20;
	char	*ts1 = "Ola A!";

	printf("Test%d: %%c%%d  %%s (11)\n", index);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%c%d  %s", tc1, ti1, ts1);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%c%d  %s", tc1, ti1, ts1);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	char	*ts21 = "Ola ";
	char	*ts22 = "Mundo ";
	char	*ts23 = "42 ";
	
	index++;
	printf("Test%d: %%s%%s%%s -- %%p%%%% (26)\n", index);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%s%s%s -- %p%%", ts21, ts22, ts23, ts21);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%s%s%s -- %p%%", ts21, ts22, ts23, ts21);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	void		*tp3 = "42";
	int			i31 = 100;
	int			i32 = -100;
	unsigned int u3 = UINT_MAX;
	
	index++;
	printf("Test%d: %%p%%i%%d !!!! %%%%u%% (33)\n", index);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%p%i%d !!!! %%%u%%", tp3, i31, i32, u3);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%p%i%d !!!! %%%u%%", tp3, i31, i32, u3);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n\n", 2);


	unsigned int x41 = UINT_MAX / 6;
	unsigned int x42 = INT_MIN;
	
	index++;
	printf("Test%d: %%x | %%X - %%x | %%X (37)\n", index);
	fflush(stdout);

	write(1, "   printf    -> ", 16);
	count = printf("%x|%X - %x|%X", x41, x41, x42, x42);
	fflush(stdout);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n\n", 2);

	write(1, "   ft_printf -> ", 17);
	count = ft_printf("%x|%X - %x|%X", x41, x41, x42, x42);
	write(1, " | Characters written: ", 24);
	ft_putnbr(count);
	write(1, "\n", 1);

	write(1, "\n", 1);

	printf("|--------------------------------------------------------|\n");
	printf("|               Tests Multiple Conversions               |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	test_close_fd()
{
	printf("|--------------------------------------------------------|\n");
	printf("|                     Tests Close Fd                     |\n");
	printf("|--------------------------------------------------------|\n\n");

	char			*t1 = "Mundo";
	char			*t2 = "42";
	unsigned int	x = UINT_MAX;

	fclose(stdout);
	fprintf(stderr, "%d\n", printf("Ola %s %s! %x", t1, t2, x));
	fprintf(stderr, "%d\n", ft_printf("Ola %s %s! %x", t1, t2, x));

	printf("|--------------------------------------------------------|\n");
	printf("|                     Tests Close Fd                     |\n");
	printf("|--------------------------------------------------------|\n\n");
}

void	separator()
{
    printf("\n");
    printf("|||====================================================|||\n");
    printf("|||====    ====    ====    ====    ====    ====    ====|||\n");
    printf("|||    ====    ====    ====    ====    ====    ====    |||\n");
    printf("|||====    ====    ====    ====    ====    ====    ====|||\n");
    printf("|||====================================================|||\n");
    printf("\n\n");
}

int main()
{
	test_characters();
	separator();
	test_strings();
	separator();
	test_pointers();
	separator();
	test_integer_d();
	separator();
	test_integer_i();
	separator();
	test_unsigned_integer();
	separator();
	test_hexa_lower();
	separator();
	test_hexa_upper();
	separator();
	test_percent();
	separator();
	test_multiple();
	separator();
	test_close_fd();
}
*/