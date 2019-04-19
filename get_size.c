/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:13:02 by naali             #+#    #+#             */
/*   Updated: 2019/01/31 18:18:01 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "opts.h"

/*
** Recupere la taille du nombre uniquement.
*/

int		get_size_signed(t_lli nb, t_lli base, t_lli *mod)
{
	int		size;

	size = 1;
	*mod = 1;
	if (nb > 0)
		nb = nb * -1;
	while (nb < (-base + 1))
	{
		nb = nb / base;
		*mod = *mod * base;
		size = size + 1;
	}
	return (size);
}

int		get_size_unsigned(t_ulli nb, t_ulli base, t_ulli *mod)
{
	int		size;

	size = 1;
	*mod = 1;
	while (nb > (base - 1))
	{
		nb = nb / base;
		*mod = *mod * base;
		size = size + 1;
	}
	return (size);
}
