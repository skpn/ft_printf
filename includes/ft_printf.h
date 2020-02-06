/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:00:55 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/06 19:37:05 by sikpenou         ###   ########.fr       */
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
# define PF_TYPES "cspduxb"
# define FLAG_P 0
# define FLAG_M 1
# define FLAG_H 2
# define FLAG_0 3
# define FLAG_S 4
# define NB_PF_FLAGS 5
# define PF_FLAGS "+-#0 "
# define FLD_HH 1
# define FLD_H 2
# define FLD_L 8
# define FLD_LL 16
# define NB_FLAGS 5

# define ERROR_NO_TYPE USER_ERRORS_START

typedef struct	s_pf_arg
{
	unsigned	type;
	unsigned	width;
	unsigned	has_prec;
	unsigned	prec;
	unsigned	field;
	void		*value;
	char		flag[NB_PF_FLAGS];
}				t_pf_arg;

typedef struct	s_pf
{
	unsigned	pos;
	unsigned	buf_size;
	t_head		args;
	va_list		ap;
	char		*format;
	char		*result;
}				t_pf;

int				alloc_new_arg(t_pf *pf);

int				parse_pf_format(t_pf *pf);
int				print_error_pf(int check_ret, t_pf *pf);

#endif