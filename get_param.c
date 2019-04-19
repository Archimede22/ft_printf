/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 12:04:21 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 18:10:55 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			get_flaglen(t_param *param, const char *format, int *i)
{
	if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		param->flags |= hh;
		(*i) += 1;
	}
	else if (format[*i] == 'h')
		param->flags |= h;
	else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
		param->flags |= ll;
		(*i) += 1;
	}
	else if (format[*i] == 'l')
		param->flags |= l;
	else if (format[*i] == 'L')
		param->flags |= L;
	else
		--(*i);
	++(*i);
}

t_bln			get_flagopt(t_param *param, const char *format, int *i)
{
	if (format[*i] == '#')
		param->flags |= hash;
	else if (format[*i] == '0')
		param->flags |= zero;
	else if (format[*i] == '-')
		param->flags |= moins;
	else if (format[*i] == '+')
	{
		param->flags &= ~espace;
		param->flags |= plus;
	}
	else if (format[*i] == ' ')
	{
		if (!(param->flags & plus))
			param->flags |= espace;
	}
	else if (format[*i] == '.' && (format[(*i) + 1] < '0'
				|| format[(*i) + 1] > '9'))
		param->flags |= point;
	else
		return (FALSE);
	++(*i);
	return (TRUE);
}

t_bln			get_vals(t_param *param, const char *format, int *i)
{
	t_bln ret;

	ret = TRUE;
	if (format[*i] == '.' && format[(*i) + 1] >= '0' && format[(*i) + 1] <= '9')
	{
		++(*i);
		param->prec = ft_atoi(format + (*i));
		while (format[*i] >= '0' && format[*i] <= '9')
			++(*i);
	}
	else if ((format[*i] >= '0' && format[*i] <= '9'))
	{
		param->width = ft_atoi(format + (*i));
		while ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '-')
			++(*i);
		if (format[*i] == '.' && (format[(*i) + 1] < '0'
					|| format[(*i) + 1] > '9'))
		{
			param->flags |= point;
			++(*i);
		}
	}
	else
		ret = FALSE;
	return (ret);
}

t_bln			get_type(t_param *param, const char *format, int *i)
{
	t_bln ret;

	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' ||
			format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' ||
			format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' ||
			format[*i] == 'f' || format[*i] == '%')
		ret = TRUE;
	else
		ret = FALSE;
	param->type = format[*i];
	if (param->flags & point)
		param->prec = 0;
	else if (param->prec == -1 && param->type == 'f')
		param->prec = 6;
	if (param->prec >= 0 && param->flags & zero && param->type != 'f')
		param->flags &= ~zero;
	if (param->type == 'p' && param->flags & plus)
		param->flags &= ~espace;
	++(*i);
	return (ret);
}
