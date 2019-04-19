/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:35:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/06 15:20:41 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	enum		e_boolean
{
	ERROR = -1,
	FALSE = 0,
	TRUE = 1
}					t_bln;

typedef enum		e_flags
{
	hh = 1,
	h = 2,
	l = 4,
	ll = 8,
	L = 16,
	hash = 32,
	zero = 64,
	moins = 128,
	plus = 256,
	espace = 512,
	point = 1024,
	neg = 2048,
}					t_flags;

typedef struct		s_param
{
	int				id;
	char			type;
	int				flags;
	int				width;
	int				prec;
	va_list			ap;
}					t_param;

typedef struct		s_ctof
{
	char			conv;
	int				(*f)(t_param *, va_list);
}					t_ctof;

typedef union		u_zero
{
	long long		signe[2];
	long double		nb;
}					t_zero;

int					ft_printf(const char *format, ...);
void				get_flaglen(t_param *param, const char *format, int *i);
t_bln				get_flagopt(t_param *param, const char *format, int *i);
t_bln				get_vals(t_param *param, const char *format, int *i);
t_bln				get_type(t_param *param, const char *format, int *i);
int					print_param(t_ctof *ctof, t_param *param, va_list ap);
int					print_string(const char *str, int *pos);
int					get_nb_param(const char *format);
int					modif_pos(int pos, const char *format);
t_param				*create_param(const char *format);
void				create_ctof(t_ctof *ctof);
int					c_param(t_param *p, va_list ap);
int					s_param(t_param *p, va_list ap);
int					p_param(t_param *p, va_list ap);
int					prct_param(t_param *p, va_list ap);
int					d_param(t_param *p, va_list ap);
int					i_param(t_param *p, va_list ap);
int					o_param(t_param *p, va_list ap);
int					u_param(t_param *p, va_list ap);
int					x_param(t_param *p, va_list ap);
int					bigx_param(t_param *p, va_list ap);
int					f_param(t_param *p, va_list ap);

#endif
