/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_char_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:58:03 by skpn              #+#    #+#             */
/*   Updated: 2020/02/11 11:14:36 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		expand_type_c(t_pf_arg *arg)
{
	arg->stack_str[0] = arg->value;
	arg->raw_len = 1;
	return (EXIT_SUCCESS);
}

int		expand_type_s(t_pf_arg *arg)
{
	int		check_ret;

	arg->raw_len = ft_strlen((char *)arg->value);
	if (arg->raw_len > PF_BUF)
	{
		if (!(arg->malloc_str = (char *)malloc(arg->raw_len + 1)))
			return (ERROR_MALLOC);
		ft_strcpy(arg->malloc_str, (char *)arg->value);	
	}
	else
	{
		ft_strcpy(arg->stack_str, (char *)arg->value);	
	}
	return (EXIT_SUCCESS);
}