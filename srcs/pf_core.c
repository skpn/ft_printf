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
	char		c;
	t_pf_arg	*arg;

	arg = &pf->arg;
	// printf("before while, format [%u]: %hhd\n", pf->format_pos, pf->format[pf->format_pos]);
	while ((c = pf->format[pf->format_pos++]) != 0)
	{
		// printf("line %d, c: %hhd (%c)\n", __LINE__, c, c);
		if (ft_ischarset(c, PF_FLAGS))
			parse_pf_arg_flag(pf, arg, c);
		else if (c == '.' || c == '*' || ft_ischarset(c, "123456789"))
		{
			parse_pf_arg_size(pf, arg, &arg->width, c);
			printf("pos after get size: %u, %c\n"
				, pf->format_pos, pf->format[pf->format_pos]);
		}
		else if (c == 'h' || c == 'l')
			parse_pf_arg_field(pf, arg, c);
		else if (ft_ischarset(c, PF_TYPES))
			return (parse_pf_arg_type(pf, arg, c));
		else
		{
			printf("bad type: %c\n", c);
			return (ERROR_BAD_TYPE);
		}
	}
	return (ERROR_NO_TYPE);
}

int		expand_pf_format(t_pf *pf)
{
	char	c;
	int		check_ret;

	pf->pos = 0;
	while ((c = pf->format[pf->format_pos++]) != 0)
	{
		// printf("bef parsing, pos %u, c: %hhd\n", pf->format_pos, c);
		if (c == '%')
		{
			if ((c = pf->format[pf->format_pos]) != '%' && c != 0
				&& (check_ret = parse_pf_arg(pf)) != EXIT_SUCCESS)
				return (check_ret);
			ft_memset(&pf->arg, 0, sizeof(pf->arg));
		}
		else
		{
			// printf("pos: %u, c: %c\n", pf->pos, c);
			pf->str[pf->pos++] = c;
			if (pf->pos == PF_BUF_SIZE
				&& ft_realloc((void **)&pf->str, pf->size, PF_BUF_SIZE)
				!= EXIT_SUCCESS)
				return (ERROR_MALLOC);
		}
	}
	pf->str[pf->pos] = 0;
	return (EXIT_SUCCESS);
}

void	init_pf_func_tab(t_pf *pf)
{
	pf->func[TYPE_C] = &expand_type_c;
	pf->func[TYPE_S] = &expand_type_s;
	pf->func[TYPE_D] = &expand_type_d;
	// printf("pf func 0: %p, expand type c: %p\n", pf->func[TYPE_C], &expand_type_c);
}

int		core_pf_2(t_pf *pf)
{
	int			check_ret;
	t_func_pf	func[NB_PF_TYPES];

	if (PF_BUF_SIZE < 1 || PF_BUF_SIZE % 8)
		return (EXIT_FAILURE);
	// printf("at line %d, pf address: %p\n", __LINE__, pf);
	pf->func = func;
	init_pf_func_tab(pf);
	if (!(pf->str = (char *)malloc(PF_BUF_SIZE)))
		return (ERROR_MALLOC);
	pf->size = PF_BUF_SIZE;
	if ((check_ret = expand_pf_format(pf)) != EXIT_SUCCESS)
		return (check_ret);
	return (EXIT_SUCCESS);
}