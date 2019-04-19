/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:35:42 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 15:45:13 by jucapik          ###   ########.fr       */
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
		while (i++ < sptw)
			write(1, " ", 1);
		return (sptw);
	}
	return (0);
}

int				c_param(t_param *p, va_list ap)
{
	char	c;
	int		total;

	c = (char)va_arg(ap, int);
	total = 1;
	if (!(p->flags & moins))
		total += write_sp(p, 1);
	write(1, &c, 1);
	if (p->flags & moins)
		total += write_sp(p, 1);
	return (total);
}
