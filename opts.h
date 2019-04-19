/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:44:22 by naali             #+#    #+#             */
/*   Updated: 2019/02/12 15:40:30 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H

# include <stdarg.h>
# include "ft_printf.h"

# define BASESX "0123456789abcdef"
# define BASEX "0123456789ABCDEF"

typedef long long int			t_lli;
typedef unsigned long long int	t_ulli;

typedef struct					s_opt
{
	char						c;
	unsigned char				uc;
	short int					si;
	short unsigned int			sui;
	int							i;
	unsigned int				ui;
	long int					li;
	long unsigned int			lui;
	long long int				lli;
	unsigned long long int		ulli;
	double						d;
	long double					ld;
}								t_opt;

typedef struct					s_nbr
{
	t_lli						nb;
	t_lli						base;
	t_lli						mod;
	t_ulli						unb;
	t_ulli						ubase;
	t_ulli						umod;
}								t_nbr;

int								get_size_signed(t_lli nb,
		t_lli base, t_lli *mod);
int								get_size_unsigned(t_ulli nb,
		t_ulli base, t_ulli *mod);
int								put_nbr_base_signed(t_lli nb,
		t_lli base, t_lli mod);
int								put_nbr_base_unsigned(t_ulli nb,
		t_ulli base, t_ulli mod, int opt);
t_lli							get_type_int_signed(t_param *p,
		va_list ap);
t_ulli							get_type_int_unsigned(t_param *p,
		va_list ap);
int								print_prec_signed(t_nbr nb,
		t_param *p, int size);
int								print_prec_unsigned(t_nbr nb,
		t_param *p, int size, int opt);
void							print_nb_char(char c, int nb);
int								print_coma_dbl(long double nb, int prec);
int								print_double_entier(long double nb, int prec);
void							init_union(t_zero *u);
int								get_ld_signe(long double nb);
void							print_point(t_param *p);

#endif
