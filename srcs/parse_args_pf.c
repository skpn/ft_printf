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

int		parse_pf_arg(t_pf *pf)
{
	int			check_ret;
	char		c;
	t_pf_arg	*arg;

	if ((check_ret = alloc_new_arg(pf)) != EXIT_SUCCESS)
		return (check_ret);
	arg = pf->args.last->content;
	while ((c = pf->format[pf->pos]) != 0)
	{
		if (ft_ischarset(c, PF_TYPES))
			return (parse_pf_arg_type(pf, arg, c));
		else if (ft_ischarset(c, PF_FLAGS))
			parse_pf_arg_flag(pf, arg, c);
		else if (c == '.' || c == '*' || ft_ischarset(c, "123456789"))
			parse_pf_arg_size(pf, arg, &arg->width, c);
		else if (c == 'h' || c == 'l')
			parse_pf_arg_field(pf, arg, c);
		else
			++pf->pos;
	}
	if (c)
		return (ERROR_NO_TYPE);
	return (ERROR_BAD_TYPE);
}

int		parse_pf_format(t_pf *pf)
{
	int		check_ret;

	pf->pos = 0;
	while (pf->format[pf->pos])
	{
		if (pf->format[pf->pos] == '%')
		{
			if (pf->format[++pf->pos] == '%')
				++pf->pos;
			else if (pf->format[pf->pos] != 0)
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
	return (EXIT_SUCCESS);
}