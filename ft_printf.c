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
		count = ft_putnbr_adress_pf((unsigned long)va_arg (var, void *), 16);
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

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	var;
	int		res;

	if (!str)
		return (-1);
	count = 0;
	va_start(var, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			res = ft_format_check(var, (char *)str);
			if (res == -1)
				return (-1);
			count += res;
		}
		else
			count += ft_putchar_pf(*str);
		str++;
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

    count = ft_printf("%c e um caracter e %s e uma string e %d e um numero decimal\n", c,str, nb);
    ft_printf("ft_printf: %d\n", count);
    printf("printf: %d\n", count);
    return (0);
} */
/* #include <limits.h>
#include <stdio.h>

void simple(void)
{
	int count1 = 0;
	int count2 = 0;
	ft_printf("======Testing simple======\n\n");
	count1 = ft_printf("Hello, world!\n");
	count2 = printf("Hello, world!\n");
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void chars(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing chars======\n\n");
	ft_printf("---Printing a char:---\n");
	count1 = ft_printf("%c\n", 'A');
	count2 = printf("%c\n", 'A');
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing a char in a sentence:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("This is char %c\n", 'x');
	count2 = printf("This is char %c\n", 'x');
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void strings(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing strings======\n\n");
	ft_printf("---Printing a string:---\n");
	count1 = ft_printf("%s\n", "Hello!");
	count2 = printf("%s\n", "Hello!");
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing a string in a sentence:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("Today is %s\n", "Monday");
	count2 = printf("Today is %s\n", "Monday");
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing a NULL string:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("A Null string is: %s\n", NULL);
	count2 = printf("A Null string is: %p\n", NULL);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void numbers_d(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing decimals======\n\n");
	ft_printf("---Printing a decimal:---\n");
	count1 = ft_printf("%d\n", 42);
	count2 = printf("%d\n", 42);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing a hexa in decimal:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%d\n", 0x2a);
	count2 = printf("%d\n", 0x2a);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN---:\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%d\n", INT_MIN);
	count2 = printf("%d\n", INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MAX:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%d\n", INT_MAX);
	count2 = printf("%d\n", INT_MAX);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN - INT_MIN:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%d\n", INT_MIN - INT_MIN);
	count2 = printf("%d\n", INT_MIN - INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void numbers_i(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing integers======\n\n");
	ft_printf("---Printing an integer:---\n");
	count1 = ft_printf("%i\n", 42);
	count2 = printf("%i\n", 42);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing a hexa in integer (decimal):---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%i\n", 0x2a);
	count2 = printf("%i\n", 0x2a);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%i\n", INT_MIN);
	count2 = printf("%i\n", INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MAX:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%i\n", INT_MAX);
	count2 = printf("%i\n", INT_MAX);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN - INT_MIN:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%i\n", INT_MIN - INT_MIN);
	count2 = printf("%i\n", INT_MIN - INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void low_hexa(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing lowercase hexas======\n\n");
	ft_printf("---Printing an hexa:---\n");
	count1 = ft_printf("%x\n", 42);
	count2 = printf("%x\n", 42);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%x\n", INT_MIN);
	count2 = printf("%x\n", INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MAX:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%x\n", INT_MAX);
	count2 = printf("%x\n", INT_MAX);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing Negative:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%x\n", -42);
	count2 = printf("%x\n", -42);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void upper_hexa(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing uppercase hexas======\n\n");
	ft_printf("---Printing an hexa:---\n");
	count1 = ft_printf("%X\n", 42);
	count2 = printf("%X\n", 42);
	fflush(stdout);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%X\n", INT_MIN);
	count2 = printf("%X\n", INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MAX:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%X\n", INT_MAX);
	count2 = printf("%X\n", INT_MAX);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing Negative:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%X\n", -42);
	count2 = printf("%X\n", -42);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);
}

void numbers_u(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing unsigned======\n\n");
	ft_printf("---Printing an unsigned:---\n");
	count1 = ft_printf("%u\n", 42);
	count2 = printf("%u\n", 42);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MAX:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%u\n", INT_MAX);
	count2 = printf("%u\n", INT_MAX);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing INT_MIN:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%u\n", INT_MIN);
	count2 = printf("%u\n", INT_MIN);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing UINT_MAX:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%u\n", UINT_MAX);
	count2 = printf("%u\n", UINT_MAX);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

}

void pointer(void)
{
	int	count1 = 0;
	int	count2 = 0;
	int n = 50;
	char c = 'a';
	void *p = NULL;

	ft_printf("\n======Testing adresses======\n\n");
	ft_printf("---Printing the adress of an int n:---\n");
	count1 = ft_printf("%p\n", (void *)&n);
	count2 = printf("%p\n", (void *)&n);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("---Printing the adress of a char c:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%p\n", (void *)&c);
	count2 = printf("%p\n", (void *)&c);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");
	
	ft_printf("---Printing the adress of a void * NULL:---\n");
	count1 = 0;
	count2 = 0;

	count1 = ft_printf("%p\n", p);
	count2 = printf("%p\n", p);
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

}

void others(void)
{
	int	count1 = 0;
	int	count2 = 0;

	ft_printf("\n======Testing percentage======\n\n");
	count1 = ft_printf("%%\n");
	count2 = printf("%%\n");
	ft_printf("\n_Number of bytes printed_\noriginal: %d mine: %d\n",
	count2, count1);

	ft_printf("\n");

	ft_printf("\n======Testing NULL (no format)======\n");
	count1 = ft_printf(NULL);
	count2 = printf(NULL);
	ft_printf("_Returned_\noriginal: %d mine: %d\n",
	count2, count1);
}

int main(void)
{
	simple();
	ft_printf("\n");
	chars();
	ft_printf("\n");
	strings();
	ft_printf("\n");
	numbers_d();
	ft_printf("\n");
	numbers_i();
	ft_printf("\n");
	low_hexa();
	ft_printf("\n");
	upper_hexa();
	ft_printf("\n");
	numbers_u();
	ft_printf("\n");
	pointer();
	ft_printf("\n");
	others();
	ft_printf("\n");
} */