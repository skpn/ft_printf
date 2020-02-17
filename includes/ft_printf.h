/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:00:55 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/13 12:59:47 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"

# define TYPE_C 0
# define TYPE_S 1
# define TYPE_P 2
# define TYPE_D 3
# define TYPE_U 4
# define TYPE_X 5
# define TYPE_B 6
# define NB_PF_TYPES 7
# define PF_TYPES "cspduxb"
# define FLAG_P 0
# define FLAG_M 1
# define FLAG_H 2
# define FLAG_Z 3
# define FLAG_S 4
# define NB_PF_FLAGS 5
# define PF_FLAGS "+-#0 "
# define FLD_HH 1
# define FLD_H 2
# define FLD_L 8
# define FLD_LL 16
# define NB_FIELDS 5

# define PF_BUF_SIZE 5000
# define NB_PF_ARGS 100

# define ERROR_NO_TYPE 0
# define ERROR_BAD_TYPE 1
# define ERROR_PF_BUF_TOO_SMALL 2
# define ERROR_TOO_MANY_PF_ARGS 3

typedef struct		s_pf_arg
{
	unsigned char	type_char;
	unsigned		type;
	unsigned		width;
	unsigned		has_prec;
	unsigned		prec;
	unsigned		field;
	long long		value;
	unsigned		raw_len;
	unsigned		final_len;
	char			*str;
	char			flag[NB_PF_FLAGS];
}					t_pf_arg;

typedef int			(*t_func_pf)(t_pf *pf, t_pf_arg *);

typedef struct		s_pf
{
	unsigned		pos;
	unsigned		size;
	unsigned		format_len;
	unsigned		nb_args;
	unsigned		current_arg;
	t_pf_arg		*args;
	va_list			ap;
	char			*format;
	char			arg_buf[PF_BUF_SIZE];
	char			*result;
	t_func_pf		*func;
}					t_pf;

int					alloc_new_arg(t_pf *pf);

void				exit_pf(t_pf *pf);
int					expand_pf_arg(t_head *args, t_lst *lst_arg);
int					expand_type_c(t_pf *pf, t_pf_arg *arg);
int					expand_type_s(t_pf *pf, t_pf_arg *arg);

int					parse_pf_format(t_pf *pf);
void				parse_pf_arg_field(t_pf *pf, t_pf_arg *arg, unsigned char c);
void				parse_pf_arg_flag(t_pf *pf, t_pf_arg *arg, unsigned char c);
void				parse_pf_arg_size(t_pf *pf, t_pf_arg *arg, unsigned *size
	, unsigned char c);
int					parse_pf_arg_type(t_pf *pf, t_pf_arg *arg, unsigned char c);
int					parse_pf_arg_value(t_pf *pf, t_pf_arg *arg);

int					print_error_pf(t_pf *pf, int error);
int					print_pf_arg(void **args, unsigned arg_nb);
void				print_pf_args(t_pf *pf);

#endif