/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:39:11 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:37:39 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

static void		mod_width_prec(t_nbr nb, t_param *p, int *width, int *prec)
{
	if ((p->flags & hash) && p->type == 'o' && nb.unb > 0)
		(*prec == 0) ? (*width -= 1) : (*prec -= 1);
	if ((p->flags & hash) && (p->type == 'x' || p->type == 'X') && nb.unb > 0)
		*width -= 2;
	if (*width < 0)
		*width = 0;
	if (*prec < 0)
		*prec = 0;
}

static void		print_sharp(t_nbr nb, t_param *p, int *size, int opt)
{
	if (nb.unb > 0 || p->type == 'p')
	{
		if (p->flags & hash && opt == 1)
		{
			*size = *size + 1;
			ft_putchar('0');
		}
		if ((p->flags & hash && opt == 2) || opt == -1)
		{
			*size = *size + 2;
			ft_putchar('0');
			ft_putchar('x');
		}
		else if (p->flags & hash && opt == 3)
		{
			*size = *size + 2;
			ft_putchar('0');
			ft_putchar('X');
		}
	}
}

static void		print_nb_uns_int(t_nbr nb, t_param *p, int *size, int opt)
{
	if (nb.unb == 0 && p->prec == 0)
	{
		if (nb.unb == 0 && p->prec == 0 && p->flags & hash && p->type == 'o')
		{
			*size = 1;
			put_nbr_base_unsigned(nb.unb, nb.ubase, nb.umod, opt);
		}
		else if (p->width > 0)
		{
			*size = 1;
			ft_putchar(' ');
		}
		else if (nb.unb == 0 && p->prec == 0 && p->type == 'p')
			*size -= 1;
		else
			*size = 0;
	}
	else
		put_nbr_base_unsigned(nb.unb, nb.ubase, nb.umod, opt);
}

void			print_prec_unsigned_helper(t_param *p, int size,
		int *width, int *prec)
{
	*prec = 0;
	*width = 0;
	if (p->prec >= 0)
		p->flags |= point;
	if (p->prec > size && p->prec > 0)
		*prec = p->prec - size;
	if (p->width > (size + *prec) && p->width > 0)
		*width = p->width - (size + *prec);
}

int				print_prec_unsigned(t_nbr nb, t_param *p, int size, int opt)
{
	int		prec;
	int		width;

	print_prec_unsigned_helper(p, size, &width, &prec);
	mod_width_prec(nb, p, &width, &prec);
	if (!(p->flags & moins))
	{
		if (p->flags & zero && !(p->flags & point) && prec == 0)
			ft_swap(&width, &prec);
		print_nb_char(' ', width = ((p->type == 'p') ? (width - 2) : width));
	}
	if (p->flags & hash || p->type == 'p')
		print_sharp(nb, p, &size, opt);
	if (p->flags & zero || prec > 0)
		print_nb_char('0', prec);
	print_nb_uns_int(nb, p, &size, opt);
	if (p->flags & moins)
		print_nb_char(' ', width = ((p->type == 'p') ? (width - 2) : width));
	return (((width < 0) ? 0 : width) + prec + size);
}
