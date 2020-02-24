/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:38:50 by skpn              #+#    #+#             */
/*   Updated: 2020/02/24 11:09:05 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int		parse_pf_arg_value(t_pf *pf, t_pf_arg *arg)
{
	if (arg->field == FLD_HH)
		arg->value = (char)va_arg(pf->ap, int);
	else if (arg->field == FLD_H)
		arg->value = (short)va_arg(pf->ap, int);
	else if (arg->field == FLD_L)
		arg->value = va_arg(pf->ap, long);
	else
		arg->value = va_arg(pf->ap, long long);
	// printf("calling func type: %u, addr: %p\n", arg->type, pf->func[arg->type]);
	return (pf->func[arg->type](pf, arg));
}

int		parse_pf_arg_type(t_pf *pf, t_pf_arg *arg, unsigned char c)
{
	arg->type_char = c;
	if (c == 'c')
		arg->type = TYPE_C;
	else if (c == 's')
		arg->type = TYPE_S;
	else if (c == 'p')
		arg->type = TYPE_P;
	else if (c == 'd')
		arg->type = TYPE_D;
	else if (c == 'u')
		arg->type = TYPE_U;
	else if (c == 'x')
		arg->type = TYPE_X;
	else if (c == 'b')
		arg->type = TYPE_B;
	// ++pf->format_pos;
	printf("end of parse type, type: %u, format pos: %u, format[pos]: %hhd\n"
		, arg->type, pf->format_pos, pf->format[pf->format_pos]);
	return (parse_pf_arg_value(pf, arg));
}

void	parse_pf_arg_size(t_pf *pf, t_pf_arg *arg, unsigned *size
	, unsigned char c)
{
	printf("c: %c\n", c);
	if (c == '.')
	{
		arg->has_prec = 1;
		c = pf->format[pf->format_pos++];
		size = &arg->prec;
	}
	printf("post dot, c: %c\n", c);
	if (c == '*')
	{
		*size = va_arg(pf->ap, long long);
	}
	else
	{
		*size = 0;
		while (ft_ischarset(c, "0123456789"))
		{
			*size = *size * 10 + c - 48;
			c = pf->format[pf->format_pos++];
		}
		--pf->format_pos;
	}
	if ((int)(*size) < 0)
		*size = 0;
}

void	parse_pf_arg_flag(t_pf *pf, t_pf_arg *arg, unsigned char c)
{
	(void)pf;
	if (c == '+')
		arg->flag[FLAG_P] = 1;
	else if (c == '-')
		arg->flag[FLAG_M] = 1;
	else if (c == '#')
		arg->flag[FLAG_H] = 1;
	else if (c == '0')
		arg->flag[FLAG_Z] = 1;
	else if (c == ' ')
		arg->flag[FLAG_S] = 1;
}

void	parse_pf_arg_field(t_pf *pf, t_pf_arg *arg, unsigned char c)
{
	if (c == 'h')
	{
		arg->field = 2;
		if (pf->format[++pf->pos] == 'h')
		{
			arg->field = 1;
			while (pf->format[pf->pos] == 'h')
				++pf->pos;
		}
	}
	if (c == 'l')
	{
		arg->field = 8;
		if (pf->format[++pf->pos] == 'l')
		{
			arg->field = 16;
			while (pf->format[pf->pos] == 'l')
				++pf->pos;
		}
	}
}