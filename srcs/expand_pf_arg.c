/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_pf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:08:36 by skpn              #+#    #+#             */
/*   Updated: 2020/02/11 11:20:49 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int		expand_pf_arg(t_head *args, t_lst *lst_arg)
{
	t_pf_arg	*arg;

	arg = lst_arg->content;
	printf("EXPANDING ARG:\n");
	print_pf_arg(args, lst_arg);
	return (pf->func[arg->type]));
}