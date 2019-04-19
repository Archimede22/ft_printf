/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_param_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:23:58 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/06 18:31:20 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "opts.h"

void			print_point(t_param *p)
{
	if (p->prec > 0 || p->flags & hash)
		write(1, ".", 1);
}

void			init_union(t_zero *u)
{
	u->signe[0] = 0;
	u->signe[1] = 0;
}

int				get_ld_signe(long double nb)
{
	t_zero		u;
	long long	k;
	long long	n;
	long long	c;

	init_union(&u);
	u.nb = nb;
	c = 16;
	k = u.signe[1];
	n = u.signe[1];
	c--;
	k = n >> c;
	if (k & 1)
		return (1);
	else
		return (0);
}
