/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:01:51 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/13 10:43:04 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	init_pf_func_tab(t_pf *pf)
{
	pf->func[TYPE_C] = &expand_type_c;
	pf->func[TYPE_S] = &expand_type_s;
}

int		core_pf(t_pf *pf)
{
	int			check_ret;
	t_pf_arg	args[NB_PF_ARGS];
	t_func_pf	func[NB_PF_TYPES];

	if (PF_BUF_SIZE < 2)
		return (ERROR_PF_BUF_TOO_SMALL);
	pf->args = args;
	pf->func = func;
	init_pf_func_tab(pf);
	if ((check_ret = parse_pf_format(pf)) != EXIT_SUCCESS)
		return (print_error_pf(pf, check_ret));
	if ((check_ret = expamd_pf_args(pf)) != EXIT_SUCCESS)
		return (print_error_pf(pf, check_ret));
	return (EXIT_SUCCESS);
}

int		ft_printf(char *format, ...)
{
	t_pf	pf;

	ft_memset(&pf, 0, sizeof(pf));
	pf.format = format;
	va_start(pf.ap, format);
	if (core_pf(&pf) == EXIT_SUCCESS)
		write(1, pf.result, pf.size);
	//exit_pf(&pf);
	return (pf.size);
}

#include <limits.h>
int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	ft_printf("arg1: %d, arg2: %c\n", 10, 'a');
	return (0);
}