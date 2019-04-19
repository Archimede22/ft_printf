/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:31:51 by naali             #+#    #+#             */
/*   Updated: 2019/02/12 15:21:55 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

int		print_coma_rec(long double nb, long double div, int check)
{
	long double		cp;
	t_ulli			chiffre;
	t_ulli			size;

	size = 0;
	cp = nb * div;
	chiffre = (t_ulli)((cp - (t_ulli)(cp / 1)) * 10);
	if (div > 1)
	{
		if (check == 1 && (chiffre % 10) == 9)
			size = print_coma_rec(nb, (div / 10), 1);
		else
			size = print_coma_rec(nb, (div / 10), 0);
	}
	if (check == 1)
		ft_putchar(((chiffre + check) % 10) + '0');
	else
		ft_putchar((chiffre % 10) + '0');
	return (size + 1);
}

int		print_coma_dbl(long double nb, int prec)
{
	long double		div;
	long double		cp;
	int				p;
	t_ulli			chiffre;
	int				size;

	div = 1;
	p = 1;
	size = 0;
	while (p < prec)
	{
		div *= 10;
		p++;
	}
	cp = nb * div;
	chiffre = (t_ulli)((cp - (t_ulli)(cp / 1)) * 10);
	if (chiffre >= 5)
		size = print_coma_rec(nb, (div / 10), 1);
	else
		size = print_coma_rec(nb, (div / 10), 0);
	return (size);
}
