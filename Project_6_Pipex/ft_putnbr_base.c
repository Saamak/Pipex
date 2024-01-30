/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:21:08 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/23 18:54:02 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb)
{
	int	i;

	i = 1;
	if (nb > 15)
	{
		i += ft_putnbr_base(nb / 16);
		nb = nb % 16;
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	if (nb > 9 && nb <= 16)
		ft_putchar(nb + 87);
	return (i);
}

int	ft_putnbr_big_x(unsigned int nb)
{
	int	i;

	i = 1;
	if (nb > 15)
	{
		i += ft_putnbr_big_x(nb / 16);
		nb = nb % 16;
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else if (nb > 9 && nb <= 16)
		ft_putchar(nb + 55);
	return (i);
}

int	ft_putnbr_x(unsigned int nb)
{
	int	i;

	i = 1;
	if (nb > 15)
	{
		i = i + ft_putnbr_x(nb / 16);
		nb = nb % 16;
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	if (nb > 9 && nb <= 16)
		ft_putchar(nb + 87);
	return (i);
}
