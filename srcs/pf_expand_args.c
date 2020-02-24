/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_expand_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:38:59 by skpn              #+#    #+#             */
/*   Updated: 2020/02/24 11:26:27 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int		nb_len_by_base_len(long long value, int base_len)
{
	int		len;

	len = 1;
	while (value >= base_len)
	{
		value /= base_len;
		len++;
	}
	return (len);
}

int		expand_type_d(t_pf *pf, t_pf_arg *arg)
{
	long long unsigned	print_nb;

	arg->base_len = nb_len_by_base_len(arg->value, 10);
	get_padding(pf, arg);
	if (arg->type == TYPE_D && arg->value < 0)
		print_nb = (arg->value + 1) * -1 + 1;
	else
		print_nb = arg->value;
	printf("value: %lld, print_nb: %llu\n", arg->value, print_nb);
	print_pf_arg(arg);
	return (EXIT_SUCCESS);
}

int		expand_type_s(t_pf *pf, t_pf_arg * arg)
{
	int		check_ret;

	print_pf_arg(arg);
	if (arg->value == 0)
		arg->value = (long long)"(null)";
	arg->base_len = ft_strlen((char *)arg->value);
	if ((check_ret = get_padding(pf, arg)) != EXIT_SUCCESS)
		return (check_ret);
	if (arg->filler_len > 0)
		ft_memset(pf->str + pf->pos, arg->filler, arg->filler_len);
	pf->pos += arg->filler_len;
	printf("pf pos: %u, str: '%.*s', value: '%.*s'\n"
		, pf->pos, pf->pos, pf->str, arg->base_len, (char *)arg->value);
	ft_memcpy(pf->str + pf->pos, (char *)arg->value, arg->base_len);
	pf->pos += arg->base_len;
	return (EXIT_SUCCESS);
}

int		expand_type_c(t_pf *pf, t_pf_arg *arg)
{
	unsigned char	str[2];

	str[0] = arg->value;
	str[1] = 0;
	arg->value = (long long)str;
	arg->type = TYPE_S;
	return (expand_type_s(pf, arg));
}