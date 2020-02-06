/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_pf->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:44:47 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/06 19:33:03 by sikpenou         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	get_flag(t_pf *pf, t_pf_arg *arg, unsigned char c)
{
	if (c == '+')
		arg->flag[FLAG_P] = 1;
	else if (c == '-')
		arg->flag[FLAG_M] = 1;
	else if (c == '#')
		arg->flag[FLAG_H] = 1;
	else if (c == '0')
		arg->flag[FLAG_0] = 1;
	else if (c == ' ')
		arg->flag[FLAG_S] = 1;
	++pf->pos;
}

int		parse_pf_arg(t_pf *pf)
{
	int			check_ret;
	char		c;
	t_pf_arg	*arg;

	if ((check_ret = alloc_new_arg(pf)) != EXIT_SUCCESS)
		return (check_ret);
	arg = pf->args.last->content;
	while ((c = pf->format[pf->pos]))
	{
		if (ft_ischarset(c, PF_TYPES))
			return (get_type(pf, arg, c));
		else if (ft_ischarset(c, PF_FLAGS))
			get_flag(pf, arg, c);
		else if (c == '*' || ft_ischarset(c, "0123456789"))
			get_size(pf, arg, &arg->width, c);
		else if (c == '.')
		{
			arg->has_prec = 1;
			++pf->pos;
			get_size(pf, arg, &arg->prec, pf->format[pf->pos]);
		}
		else
			++pf->pos;
	}
	return (ERROR_NO_TYPE);
}

int		parse_pf_format(t_pf *pf)
{
	int		check_ret;

	pf->pos = 0;
	while (pf->format[pf->pos])
	{
		if (pf->format[pf->pos] == '%')
		{
			++pf->pos;
			if (pf->format[pf->pos] != 0 && pf->format[pf->pos] != '%')
			{
				if ((check_ret = parse_pf_arg(pf)) != EXIT_SUCCESS)
					return (check_ret);
			}
		}
		else
		{
			++pf->pos;
		}
	}
}