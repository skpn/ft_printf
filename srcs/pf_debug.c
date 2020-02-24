/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:41:12 by skpn              #+#    #+#             */
/*   Updated: 2020/02/24 11:13:04 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	print_pf_arg_value(t_pf_arg *arg)
{
	if (arg->type == TYPE_C)
		printf("value     : %c\n", (char)arg->value);
	else if (arg->type == TYPE_S)
		printf("value     : %s\n", (char *)arg->value);
	else if (arg->type == TYPE_P)
		printf("value     : %p\n", (void *)arg->value);
	else if (arg->type == TYPE_D)
		printf("value     : %d\n", (int)arg->value);
	else if (arg->type == TYPE_U)
		printf("value     : %u\n", (unsigned)arg->value);
	else if (arg->type == TYPE_X)
		printf("value     : %x\n", (unsigned)arg->value);
}

void	print_pf_arg_flags(t_pf_arg *arg)
{
	printf("flags     :");
	if (arg->flag[FLAG_P])
		printf(" PLUS ");
	if (arg->flag[FLAG_Z])
		printf(" ZERO ");
	if (arg->flag[FLAG_M])
		printf(" MINUS ");
	if (arg->flag[FLAG_S])
		printf(" SPACE ");
	if (arg->flag[FLAG_H])
		printf(" HASH ");
	printf("\n");
}

int		print_pf_arg(t_pf_arg *arg)
{
	printf("PRINTING ARG\n");
	printf("type      : %u (%c)\n", arg->type, arg->type_char);
	if (arg->width)
		printf("width     : %u\n", arg->width);
	if (arg->has_prec)
		printf("prec      : %u\n", arg->prec);
	if (arg->field)
		printf("field	  : %u\n", arg->field);
	printf("raw value : %lld\n", arg->value);
	printf("base_len  : %u\n", arg->base_len);
	printf("prefix_len: %u\n", arg->prefix_len);
	printf("filler_len: %u\n", arg->filler_len);
	print_pf_arg_value(arg);
	print_pf_arg_flags(arg);
	return (EXIT_SUCCESS);
}

void	print_pf(t_pf *pf)
{
	printf("PRINTING PF\n");
	printf("pos       : %u\n", pf->pos);
	printf("size      : %u\n", pf->size);
	printf("format    : %s\n", pf->format);
	printf("result    : %s\n", pf->str);
}