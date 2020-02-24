/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:39:27 by skpn              #+#    #+#             */
/*   Updated: 2020/02/24 10:29:13 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	get_total_len(t_pf_arg *arg)
{
	arg->total_len = arg->base_len + arg->prefix_len;
	printf("width: %u, total: %u\n", arg->width, arg->total_len);
	if (arg->width > arg->total_len)
	{
		arg->filler_len = arg->width - arg->total_len;
		arg->filler = arg->flag[FLAG_Z] ? '0' : ' ';
	}
	else if (arg->has_prec && arg->type == TYPE_S && arg->prec < arg->total_len)
		arg->base_len = arg->prec - arg->prefix_len;
	arg->total_len = arg->base_len + arg->prefix_len + arg->filler_len;
}

void	get_prefix(t_pf_arg *arg)
{
	if (arg->type == TYPE_X || arg->type == TYPE_P)
	{
		arg->prefix[0] = '0';
		arg->prefix[1] = 'x';
		arg->prefix_len = 2;
	}
}

int		get_padding(t_pf *pf, t_pf_arg *arg)
{
	get_prefix(arg);
	get_total_len(arg);
	while (arg->total_len + pf->pos >= pf->size)
	{
		if (ft_realloc((void **)&pf->str, pf->size, PF_BUF_SIZE)
			!= EXIT_SUCCESS)
		{
			return (ERROR_MALLOC);
		}
		pf->size += PF_BUF_SIZE;
	}
	return (EXIT_SUCCESS);
}