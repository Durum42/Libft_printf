/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-rio <pdel-rio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:11:15 by pdel-rio          #+#    #+#             */
/*   Updated: 2025/07/01 16:18:11 by pdel-rio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • %s Imprime una string (como se define por defecto en C).

#include "ft_printf.h"

int	ft_putstr_pf(char *str )
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	if (!str)
		str = "(null)";
	while (str[++i])
		counter += ft_putchar_pf(str[i]);
	return (counter);
}

// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.

int	ft_putnbr_pf(int n, int counter)
{
	if (n < 0)
	{
		counter += ft_putchar_pf('-');
		if (n == -2147483648)
		{
			counter += ft_putchar_pf('2');
			n = (-147483648);
		}
		n = -n;
	}
	if (n >= 10)
	{
		counter = ft_putu_pf(n / 10, counter + 1);
		ft_putchar_pf(n % 10 + '0');
		return (counter);
	}
	counter += ft_putchar_pf(n % 10 + '0');
	return (counter);
}

// • %u Imprime un número decimal (base 10) sin signo.

int	ft_putu_pf(unsigned int n, int counter)
{
	if (n >= 10)
	{
		counter = ft_putu_pf(n / 10, counter + 1);
		ft_putchar_pf(n % 10 + '0');
		return (counter);
	}
	counter += ft_putchar_pf(n % 10 + '0');
	return (counter);
}

// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.

int	ft_puthex_pf(unsigned long n, int counter, const char base)
{
	char	*bs;

	bs = "0123456789ABCDEF";
	if (base == 'x')
		bs = "0123456789abcdef";
	if (n >= 16)
	{
		counter = ft_puthex_pf(n / 16, counter + 1, base);
		ft_putchar_pf(bs[n % 16]);
		return (counter);
	}
	counter += ft_putchar_pf(bs[n % 16]);
	return (counter);
}

// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				counter;

	counter = 0;
	p = (unsigned long)ptr;
	if (!ptr)
		return (counter += ft_putstr_pf(("(nil)")));
	counter += ft_putstr_pf("0x");
	counter += ft_puthex_pf(p, 0, 'x');
	return (counter);
}
