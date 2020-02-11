/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:10:27 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/10 10:03:53 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		alloc_new_arg(t_pf *pf)
{
	t_pf_arg	*new_arg;

	new_arg = (t_pf_arg *)malloc(sizeof(*new_arg));
	if (!new_arg)
		return (ERROR_MALLOC);
	ft_memset(new_arg, 0, sizeof(*new_arg));
	if (!ft_lstadd_back_new(&pf->args, new_arg))
		return (ERROR_MALLOC);
	return (EXIT_SUCCESS);
}