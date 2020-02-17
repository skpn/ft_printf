/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:41:12 by skpn              #+#    #+#             */
/*   Updated: 2020/02/13 12:49:23 by sikpenou         ###   ########.fr       */
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

int		print_pf_arg(void **args, unsigned arg_nb)
{
	t_pf_arg	*arg;

	arg = ((t_pf_arg **)args[arg_nb]);
	printf("PRINTING ARG %u\n", arg_nb);
	printf("type      : %u (%c)\n", arg->type, arg->type_char);
	printf("width     : %u\n", arg->width);
	printf("has_prec  : %u\n", arg->has_prec);
	printf("prec      : %u\n", arg->prec);
	printf("field	  : %u\n", arg->field);
	printf("raw value : %lld\n", arg->value);
	print_pf_arg_value(arg);
	print_pf_arg_flags(arg);
	printf("str : %s\n", arg->str);
	return (EXIT_SUCCESS);
}

void	print_pf_args(t_pf *pf)
{
	ft_tabmap((void **)&pf->args, pf->nb_args, &print_pf_arg);
	printf("\n");
}

void	print_pf(t_pf *pf)
{
	printf("PRINTING PF\n");
	printf("pos       : %u\n", pf->pos);
	printf("size      : %u\n", pf->size);
	printf("format_len: %u\n", pf->format_len);
	printf("format    : %s\n", pf->format);
	printf("result    : %s\n", pf->result);
}