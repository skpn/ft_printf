/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:01:51 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/25 15:09:38 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_dprintf(int fd, char *format, ...)
{
	t_pf	pf;

	if (fd < 0)
		return (0);
	ft_memset(&pf, 0, sizeof(pf));
	pf.format = format;
	pf.fd = fd;
	va_start(pf.ap, format);
	if (core_pf_2(&pf) == EXIT_SUCCESS)
		write(pf.fd, pf.str, pf.pos);
	else
		pf.size = -1;
	easyfree((void **)&pf.str);
	return (pf.pos);
}

#include <limits.h>
int		main(int ac, char **av)
{
	int		ret;

	(void)ac;
	(void)av;
	 char *test = "haha";
	ret = ft_dprintf(1, "arg1: %p\n", test);
	printf("my ret: %u\n", ret);
	ret = printf("arg1: %p\n", test);
	printf("pf ret: %u\n", ret);
	return (0);
}