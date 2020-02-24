/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:57:02 by sikpenou          #+#    #+#             */
/*   Updated: 2020/01/24 18:32:41 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(long long n)
{
	char	nb_str[21];
	char	*pos;

	printf("n: %lld\n", n);
	*nb_str = 0;
	n ? 0 : (nb_str[20] = '0');
	if (n < 0)
		*nb_str = '-';
	if (n - 1 > n)
	{
		nb_str[20] = '8';
		n /= 10;
		pos = nb_str + 19;
	}
	else
		pos = nb_str + 20;
	n = n < 0 ? -n : n;
	while (n)
	{
		*pos = n % 10 + 48;
		printf("n: %lld, *pos: %d\n", n, *pos);
		n /= 10;
		--pos;
	}
	if (*nb_str != 0)
		*pos = '-';
	write(1, pos, nb_str + 21 - pos);
}
