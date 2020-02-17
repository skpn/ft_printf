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

	arg = &pf->args[pf->nb_args++];
	if (pf->current_arg >= NB_PF_ARGS)
		return (ERROR_TOO_MANY_PF_ARGS);
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
	int			check_ret;
	unsigned	hard_text_start;

	pf->pos = 0;
	hard_text_start = 0;
	while (pf->format[pf->pos])
	{
		if (pf->format[pf->pos] == '%')
		{
			ft_memcpy(pf->result + pf->size, pf->format + hard_text_start
				, pf->pos - hard_text_start);
			pf->size += pf->pos - hard_text_start;
			hard_text
			if (pf->format[++pf->pos] == '%')
				++pf->pos;
			else if (pf->format[pf->pos] != 0)
			{
				if ((check_ret = parse_pf_arg(pf)) != EXIT_SUCCESS)
					return (check_ret);
				hard_text_start = pf->pos;
			}
		}
		else
		{
			++pf->pos;
		}
	}
	return (EXIT_SUCCESS);
}