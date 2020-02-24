/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_expand_char_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:58:03 by skpn              #+#    #+#             */
/*   Updated: 2020/02/24 10:24:58 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		expand_type_c(t_pf *pf, t_pf_arg *arg)
{
	arg->base_len = 1;
	get_len_prefix(arg);
	get_len_suffix(arg);
	prefix_to_buf(arg);
	arg_to_buf(arg);
	suffix_to_buf(arg);
	return (EXIT_SUCCESS);
}

int		expand_type_s(t_pf *pf, t_pf_arg *arg)
{
	int		check_ret;

	arg->base_len = ft_strlen((char *)arg->value);
	get_len_prefix(arg);
	get_len_suffix(arg);
	return (EXIT_SUCCESS);
}