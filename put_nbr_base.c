/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:39:23 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:34:05 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "opts.h"

int		put_nbr_base_signed(t_lli nb, t_lli base, t_lli mod)
{
	char		chiffre;
	int			size;

	size = 0;
	if (nb > 0)
		nb = nb * -1;
	while (mod > 0)
	{
		chiffre = BASESX[((nb / mod) * -1)];
		ft_putchar(chiffre);
		nb = nb % mod;
		mod = mod / base;
		size = size + 1;
	}
	return (size);
}

int		put_nbr_base_unsigned(t_ulli nb, t_ulli base, t_ulli mod, int opt)
{
	char		chiffre;
	int			size;

	size = 0;
	while (mod > 0)
	{
		if (opt <= 2)
			chiffre = BASESX[((nb / mod))];
		else
			chiffre = BASEX[((nb / mod))];
		ft_putchar(chiffre);
		nb = nb % mod;
		mod = mod / base;
		size = size + 1;
	}
	return (size);
}
