/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:16:20 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:36:13 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "opts.h"

t_lli					get_type_int_signed(t_param *p, va_list ap)
{
	t_lli		nb;

	if (p->flags & l)
		nb = (t_lli)va_arg(ap, long int);
	else if (p->flags & ll)
		nb = (t_lli)va_arg(ap, long long int);
	else
	{
		if (p->flags & h)
			nb = (t_lli)(short int)va_arg(ap, int);
		else if (p->flags & hh)
			nb = (t_lli)(char)va_arg(ap, int);
		else
			nb = (t_lli)va_arg(ap, int);
	}
	return (nb);
}

t_ulli					get_type_int_unsigned(t_param *p, va_list ap)
{
	t_ulli		nb;

	if (p->flags & l)
		nb = (t_ulli)(long unsigned int)va_arg(ap, long unsigned int);
	else if (p->flags & ll || p->type == 'p')
		nb = (t_ulli)va_arg(ap, unsigned long long int);
	else
	{
		if (p->flags & h)
			nb = (t_ulli)(unsigned short int)va_arg(ap, unsigned int);
		else if (p->flags & hh)
			nb = (t_ulli)(unsigned char)va_arg(ap, unsigned int);
		else
			nb = (t_ulli)(unsigned int)va_arg(ap, unsigned int);
	}
	return (nb);
}
