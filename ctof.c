/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:41:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 17:08:55 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	create_ctof(t_ctof *ctof)
{
	ctof[0].conv = 'c';
	ctof[0].f = &c_param;
	ctof[1].conv = 's';
	ctof[1].f = &s_param;
	ctof[2].conv = 'p';
	ctof[2].f = &p_param;
	ctof[3].conv = 'd';
	ctof[3].f = &d_param;
	ctof[4].conv = 'i';
	ctof[4].f = &i_param;
	ctof[5].conv = 'o';
	ctof[5].f = &o_param;
	ctof[6].conv = 'u';
	ctof[6].f = &u_param;
	ctof[7].conv = 'x';
	ctof[7].f = &x_param;
	ctof[8].conv = 'X';
	ctof[8].f = &bigx_param;
	ctof[9].conv = 'f';
	ctof[9].f = &f_param;
	ctof[10].conv = '%';
	ctof[10].f = &prct_param;
	ctof[11].conv = 'N';
}
