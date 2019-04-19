/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:42:57 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 17:17:00 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

int				modif_pos(int pos, const char *format)
{
	int og_pos;

	og_pos = pos++;
	while (format[pos] == '+' || format[pos] == '-' || format[pos] == ' '
			|| format[pos] == '#' || format[pos] == '0')
		++pos;
	while (format[pos] >= '0' && format[pos] <= '9')
		++pos;
	if (format[pos] == '.')
	{
		++pos;
		while (format[pos] >= '0' && format[pos] <= '9')
			++pos;
	}
	while (format[pos] == 'h' || format[pos] == 'l' || format[pos] == 'L')
		++pos;
	if (format[pos] == 'c' || format[pos] == 's' || format[pos] == 'p'
			|| format[pos] == 'd' || format[pos] == 'i' || format[pos] == 'o'
			|| format[pos] == 'u' || format[pos] == 'x' || format[pos] == 'X'
			|| format[pos] == 'f' || format[pos] == '%')
		++pos;
	return (pos);
}

static int		print(const char *format, t_param *params,
		t_ctof ctof[11], va_list ap)
{
	int		size;
	int		i;
	int		nb_params;
	int		pos;
	int		res;

	nb_params = get_nb_param(format);
	pos = 0;
	i = 0;
	size = 0;
	while (i < nb_params)
	{
		size += print_string(format, &pos);
		if ((res = print_param(ctof, params + i, ap)) == -1)
			return (-1);
		size += res;
		pos = modif_pos(pos, format);
		i++;
	}
	size += print_string(format, &pos);
	ft_memdel((void **)&params);
	return (size);
}

int				ft_printf(const char *format, ...)
{
	t_param		*params;
	t_ctof		ctof_tab[11];
	va_list		ap;
	int			size;

	if (format == NULL)
		return (-1);
	create_ctof(ctof_tab);
	va_start(ap, format);
	params = create_param(format);
	size = print(format, params, ctof_tab, ap);
	va_end(ap);
	return (size);
}
