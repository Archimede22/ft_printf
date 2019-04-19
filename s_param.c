/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:53:20 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/12 14:38:40 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

int		write_sp(t_param *p, int wtw)
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

int		s_param(t_param *p, va_list ap)
{
	char	*s;
	t_bln	null;
	int		size;
	int		wtw;
	int		total;

	s = (char *)va_arg(ap, char *);
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		null = TRUE;
	}
	else
		null = FALSE;
	size = (p->prec == 0) ? 0 : ft_strlen(s);
	wtw = (p->prec < size && p->prec != -1) ? p->prec : size;
	total = wtw;
	if (!(p->flags & moins))
		total += write_sp(p, wtw);
	write(1, s, wtw);
	if (p->flags & moins)
		total += write_sp(p, wtw);
	if (null == TRUE)
		free(s);
	return (total);
}
