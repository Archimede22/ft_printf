/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxx_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:21:50 by naali             #+#    #+#             */
/*   Updated: 2019/02/05 17:09:24 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

int		o_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.unb = (t_lli)get_type_int_unsigned(p, ap);
	nb.ubase = 8;
	size = get_size_unsigned(nb.unb, nb.ubase, &(nb.umod));
	size = print_prec_unsigned(nb, p, size, 1);
	return (size);
}

int		x_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.unb = (t_lli)get_type_int_unsigned(p, ap);
	nb.ubase = 16;
	size = get_size_unsigned(nb.unb, nb.ubase, &(nb.umod));
	size = print_prec_unsigned(nb, p, size, 2);
	return (size);
}

int		bigx_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.unb = (t_lli)get_type_int_unsigned(p, ap);
	nb.ubase = 16;
	size = get_size_unsigned(nb.unb, nb.ubase, &(nb.umod));
	size = print_prec_unsigned(nb, p, size, 3);
	return (size);
}
