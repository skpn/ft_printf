/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:41:12 by skpn              #+#    #+#             */
/*   Updated: 2020/02/10 14:54:51 by skpn             ###   ########.fr       */
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

int		print_pf_arg(t_head *args, t_lst *lst_arg)
{
	t_pf_arg	*arg;

	(void)args;
	arg = lst_arg->content;
	printf("PRINTING ARG\n");
	printf("type      : %u (%c)\n", arg->type, arg->type_char);
	printf("width     : %u\n", arg->width);
	printf("has_prec  : %u\n", arg->has_prec);
	printf("prec      : %u\n", arg->prec);
	printf("field	  : %u\n", arg->field);
	printf("raw value : %lld\n", arg->value);
	print_pf_arg_value(arg);
	print_pf_arg_flags(arg);
	printf("stack str : %s\n", arg->stack_str);
	printf("malloc_str: %s\n", arg->malloc_str);
	return (EXIT_SUCCESS);
}

void	print_pf_args(t_head args)
{
	ft_lstmap(&args, &print_pf_arg);
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