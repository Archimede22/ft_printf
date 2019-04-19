/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:35:08 by naali             #+#    #+#             */
/*   Updated: 2019/01/21 17:41:16 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "opts.h"

int		d_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.nb = (t_lli)get_type_int_signed(p, ap);
	nb.base = 10;
	size = get_size_signed(nb.nb, nb.base, &(nb.mod));
	size = print_prec_signed(nb, p, size);
	return (size);
}

int		i_param(t_param *p, va_list ap)
{
	t_nbr	nb;
	int		size;

	nb.nb = (t_lli)get_type_int_signed(p, ap);
	nb.base = 10;
	size = get_size_signed(nb.nb, nb.base, &(nb.mod));
	size = print_prec_signed(nb, p, size);
	return (size);
}
