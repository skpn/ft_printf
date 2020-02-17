/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_pf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:08:36 by skpn              #+#    #+#             */
/*   Updated: 2020/02/13 12:59:30 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int		expand_pf_args(t_pf *pf)
{
	t_pf_arg	*arg;
	int			check_ret;

	while (pf->current_arg < pf->nb_args)
	{
		arg = &pf->args[pf->current_arg++];
		arg->str = pf->arg_buf + pf->size;
		printf("EXPANDING ARG:\n");
		print_pf_arg((void **)&pf->args, pf->current_arg - 1);
		if ((check_ret = pf->func[arg->type](pf, arg)) != EXIT_SUCCESS)
			return (check_ret);
	}
	return (EXIT_SUCCESS);
}