/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:53:34 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/24 18:53:36 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_x(unsigned int nb);
int		ft_putnbr_big_x(unsigned int nb);
int		print_it(char it, va_list bob);
int		ft_putnbr_base(unsigned long long nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_len(int n);
int		ft_len_u(unsigned int n);
void	ft_putnbr_u(unsigned int nb);
void	ft_putnbr(int nb);
#endif
