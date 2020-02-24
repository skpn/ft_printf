/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:39:07 by skpn              #+#    #+#             */
/*   Updated: 2020/02/24 00:16:54 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int		transfer_buffer(t_pf *pf)
{
	int		check_ret;
	
	if (pf->pos == 0)
	 	return (EXIT_SUCCESS);
	// if ((check_ret = ft_realloc((void **)&pf->str, pf->size, pf->pos))
	// 	!= EXIT_SUCCESS)
	// 	return (check_ret);
	// ft_memcpy(pf->str + pf->size, pf->buffer, pf->pos);
	// pf->size += pf->pos;
	// if (pf->size > PF_RESULT_MAX_SIZE)
	// 	return (ERROR_PF_RESULT_TOO_LONG);
	// return (EXIT_SUCCESS);
}