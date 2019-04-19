/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:41:06 by naali             #+#    #+#             */
/*   Updated: 2019/02/05 17:20:34 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

int		u_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.unb = (t_ulli)get_type_int_unsigned(p, ap);
	nb.ubase = 10;
	size = get_size_unsigned(nb.unb, nb.ubase, &(nb.umod));
	size = print_prec_unsigned(nb, p, size, 0);
	return (size);
}
