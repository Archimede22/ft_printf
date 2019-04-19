/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:47:49 by naali             #+#    #+#             */
/*   Updated: 2019/01/21 18:10:19 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

int		p_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.unb = (t_lli)get_type_int_unsigned(p, ap);
	nb.ubase = 16;
	size = get_size_unsigned(nb.unb, nb.ubase, &(nb.umod));
	size = print_prec_unsigned(nb, p, size, -1);
	return (size);
}
