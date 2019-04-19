/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_entier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:12:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/12 16:06:23 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

static int		rec(unsigned long long nb, t_bln check)
{
	unsigned long long int		tp;
	unsigned long long int		ret;
	char						c;

	tp = nb % 10;
	if (check == TRUE)
	{
		if (tp != 9)
			check = FALSE;
		tp = (tp + 1) % 10;
	}
	if (nb >= 10)
		ret = 1 + rec(nb / 10, check);
	else
		ret = 1;
	if (nb < 10 && check == TRUE)
	{
		write(1, "1", 1);
		++ret;
	}
	c = tp + '0';
	write(1, &c, 1);
	return (ret);
}

static t_bln	check_prec_dbl(long double nb, int prec)
{
	unsigned long long	nb_i;
	int					nbm;
	unsigned long long	mult;

	nb_i = (unsigned long long)(nb * 10);
	nb_i %= 10;
	mult = 10;
	nbm = 0;
	while (nb_i == 9)
	{
		nb_i = (unsigned long long)(nb * mult);
		nb_i %= 10;
		++nbm;
		mult *= 10;
	}
	if (nbm > prec || (nbm == 0 && (nb_i > 5 || (nb_i == 5
		&& ((unsigned long long)(nb * (mult * 10))) % 10 > 5))
		&& prec == 0))
		return (TRUE);
	else
		return (FALSE);
}

int				print_double_entier(long double nb, int prec)
{
	unsigned long long	nb_i;
	t_bln				check;
	int					ret;

	if (nb < 0)
	{
		nb *= -1;
		ret = 1;
	}
	else
		ret = 0;
	if (nb > 18446744073709551615.0)
	{
		ft_putchar('0');
		return (1);
	}
	check = check_prec_dbl(nb, prec);
	nb_i = (unsigned long long)nb;
	ret += rec(nb_i, check);
	(void)prec;
	return (ret);
}
