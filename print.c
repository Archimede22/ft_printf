/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:27:38 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/06 17:05:24 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			print_string(const char *str, int *pos)
{
	int		size;
	int		og_pos;

	og_pos = *pos;
	size = 0;
	while (str[*pos] != '\0' && str[*pos] != '%')
	{
		++(*pos);
		size++;
	}
	if (size > 0)
		write(1, str + og_pos, size);
	return (size);
}

int			print_param(t_ctof *ctof, t_param *param, va_list ap)
{
	int		i;

	i = 0;
	while (ctof[i].conv != param->type && ctof[i].conv != 'N')
		i++;
	if (ctof[i].conv == 'N' || param->prec > 4932)
		return (0);
	return (ctof[i].f(param, ap));
}
