/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:18:18 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:37:30 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

static int		mod_width_prec(t_nbr nb, t_param *p, int *width, int *prec)
{
	if (((p->flags & plus) || (p->flags & espace)) || (nb.nb < 0))
		*width = *width - 1;
	if (*width <= 0)
		*width = 0;
	if ((p->flags & plus) && (nb.nb > 0) && *width == *prec)
	{
		*prec = *prec - 1;
		return (1);
	}
	return (0);
}

static void		print_plus_minus_space(t_nbr *nb, t_param *p, int *size)
{
	if (p->flags & plus && !(p->flags & espace) && nb->nb >= 0)
	{
		*size += 1;
		ft_putchar('+');
	}
	else if (p->flags & espace && !(p->flags & plus) && nb->nb >= 0)
	{
		*size += 1;
		ft_putchar(' ');
	}
	else if (nb->nb < 0)
	{
		*size += 1;
		ft_putchar('-');
	}
}

static void		print_nb_int(t_nbr nb, t_param *p, int *size)
{
	if (nb.nb == 0 && p->prec == 0)
	{
		if (p->width > 0 && *size <= 1)
		{
			*size = 1;
			ft_putchar(' ');
		}
		else if (*size > 1)
			*size = 1;
		else
			*size = 0;
	}
	else
		put_nbr_base_signed(nb.nb, nb.base, nb.mod);
}

static void		print_prec_signed_helper(t_param *p, int size,
		int *width, int *prec)
{
	if (p->prec > size && p->prec > 0)
		*prec = p->prec - size;
	if (p->width > (size + *prec) && p->width > 0)
		*width = p->width - (size + *prec);
}

int				print_prec_signed(t_nbr nb, t_param *p, int size)
{
	int		prec;
	int		width;
	int		flg;

	prec = 0;
	width = 0;
	print_prec_signed_helper(p, size, &width, &prec);
	flg = mod_width_prec(nb, p, &width, &prec);
	if (!(p->flags & moins))
	{
		if (p->flags & zero && prec == 0)
			ft_swap(&width, &prec);
		print_nb_char(' ', width);
	}
	if (p->flags & zero || prec > 0)
	{
		print_plus_minus_space(&nb, p, &size);
		print_nb_char('0', prec = ((p->prec == size) ? prec : (prec + flg)));
	}
	else
		print_plus_minus_space(&nb, p, &size);
	print_nb_int(nb, p, &size);
	if (p->flags & moins)
		print_nb_char(' ', width);
	return (width + prec + size + flg);
}
