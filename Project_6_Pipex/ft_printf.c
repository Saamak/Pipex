/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:55:17 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/23 18:53:55 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cast(void *pt, int i)
{
	unsigned long long	add;

	add = (unsigned long long)pt;
	if (pt == NULL)
		i = ft_putstr("(nil)");
	else
	{
		write(1, "0x", 2);
		i = ft_putnbr_base(add);
		i = i + 2;
	}
	return (i);
}

int	ft_len(int n)
{
	int	i;

	i = 1;
	ft_putnbr(n);
	if (n < 0)
	{
		i++;
		n = -n;
		if (n == -2147483648)
			i = 11;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_len_u(unsigned int n)
{
	int	i;

	i = 1;
	ft_putnbr_u(n);
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_it(char it, va_list bob)
{
	int				len;

	len = 0;
	if (it == 'c')
		len = ft_putchar(va_arg(bob, int));
	else if (it == 's')
		len = ft_putstr(va_arg(bob, char *));
	else if (it == 'p')
		len = cast(va_arg(bob, void *), len);
	else if (it == 'd' || it == 'i')
		len = ft_len(va_arg(bob, int));
	else if (it == 'u')
		len = ft_len_u(va_arg(bob, unsigned int));
	else if (it == 'x')
		len = ft_putnbr_x(va_arg(bob, unsigned int));
	else if (it == 'X')
		len = ft_putnbr_big_x(va_arg(bob, unsigned int));
	else if (it == '%')
		len = ft_putchar('%');
	va_end(bob);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	bob;

	len = 0;
	i = 0;
	va_start(bob, s);
	if (s == NULL)
		return (-1);
	while (s[i] != 0)
	{
		if (s[i] != '%')
			len = len + ft_putchar(s[i]);
		else
		{
			len = len + print_it(s[i + 1], bob);
			i++;
		}
		i++;
	}
	return (len);
}
