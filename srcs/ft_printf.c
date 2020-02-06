/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:01:51 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/06 19:31:56 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_printf(char *format, ...)
{
	int		check_ret;
	t_pf	pf;

	//if (check_ret  = init_structs_pf(&pf, format) != EXIT_SUCCESS)
	//	print_error_pf(check_ret);
	ft_memset(&pf, 0, sizeof(pf));
	pf.format = format;
	va_start(pf.ap, format);
	if ((check_ret = parse_pf_format(&pf)) != EXIT_SUCCESS)
		return (print_error_pf(check_ret, &pf));
	return (pf.buf_size);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("arg1: %s\narg2: %s\n", "arg1", "arg2");
	return (0);
}