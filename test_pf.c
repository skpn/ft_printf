/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:04:44 by sikpenou          #+#    #+#             */
/*   Updated: 2020/01/29 13:58:10 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include "includes/libft.h"

int		main(int ac, char **av)
{
	if(!ac || !av)
		return(0);
	ft_printf("test: %5.5d\n", 3);
	printf("test: %5.5d\n", 3);
	return (0);
}
