/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:03:09 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:35:44 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

static int		get_dbl_entier_size(long double nb)
{
	int		i;

	i = 1;
	if (nb < 0)
		nb = -(nb);
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void		mod_width(long double nb, t_param *p, int *width, int signe)
{
	if ((p->flags & plus) || (p->flags & espace)
			|| (nb < 0) || (nb == 0 && signe == 1))
		*width -= 1;
	if (*width < 0)
		*width = 0;
}

static void		print_minus_plus_space(long double nb,
		t_param *p, int *size, int signe)
{
	if ((p->flags & plus || p->flags & espace) && nb > 0)
	{
		*size += 1;
		ft_putchar((p->flags & plus) ? '+' : ' ');
	}
	else if (nb < 0)
		ft_putchar('-');
	if ((p->flags & plus || p->flags & espace) && nb == 0 && signe == 0)
	{
		*size += 1;
		ft_putchar((p->flags & plus) ? '+' : ' ');
	}
	if (nb == 0 && signe == 1)
	{
		*size += 1;
		ft_putchar('-');
	}
}

static void		print_prec_dbl(long double nb, t_param *p, int *size, int signe)
{
	int		width;

	width = 0;
	*size += get_dbl_entier_size(nb);
	if (p->width > *size)
		width = p->width - *size;
	mod_width(nb, p, &width, signe);
	if (p->flags & zero)
		print_minus_plus_space(nb, p, size, signe);
	if (!(p->flags & moins))
		print_nb_char((!(p->flags & zero)) ? ' ' : '0', width);
	if (!(p->flags & zero))
		print_minus_plus_space(nb, p, size, signe);
	print_double_entier(nb, p->prec);
	print_point(p);
	if (p->prec > 0)
	{
		if (nb < 0)
			nb = -(nb);
		print_coma_dbl((nb - (t_ulli)(nb / 1)),
				((p->prec > 0) ? p->prec + 1 : p->prec));
	}
	if (p->flags & moins)
		print_nb_char(' ', width);
	*size += width;
}

int				f_param(t_param *p, va_list ap)
{
	t_opt	nb;
	int		size;
	int		signe;

	nb.ld = 0;
	size = ((p->prec > 0 || p->flags & hash) ? p->prec + 1 : p->prec);
	if (p->flags & l || p->flags & L)
		nb.ld = (long double)va_arg(ap, long double);
	else
		nb.ld = (double)va_arg(ap, double);
	signe = get_ld_signe(nb.ld);
	print_prec_dbl(nb.ld, p, &size, signe);
	return ((nb.ld < 0) ? (size + 1) : (size));
}
