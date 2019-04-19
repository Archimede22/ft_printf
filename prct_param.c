/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prct_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:32:51 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 17:07:51 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

static int		write_sp(t_param *p, int wtw)
{
	int		sptw;
	int		i;

	if (p->width > wtw)
	{
		sptw = p->width - wtw;
		i = 0;
		if (!(p->flags & zero) || p->flags & moins)
		{
			while (i++ < sptw)
				write(1, " ", 1);
		}
		else
			while (i++ < sptw)
				write(1, "0", 1);
		return (sptw);
	}
	return (0);
}

int				prct_param(t_param *p, va_list ap)
{
	int		total;

	(void)ap;
	total = 1;
	if (!(p->flags & moins))
		total += write_sp(p, 1);
	write(1, "%", 1);
	if (p->flags & moins)
		total += write_sp(p, 1);
	return (total);
}
