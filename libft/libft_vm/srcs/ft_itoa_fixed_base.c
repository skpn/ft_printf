/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_fixed_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:25:33 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/13 15:28:28 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_fixed_base(long int n, unsigned base_len)
{
	unsigned	pos;
	char		*res;
	char		*base_to;

	if (base_len < 2 || base_len > 16)
		return (NULL);
	base_to = "012456789abcdef";
	pos = 0;
	while (n / ft_pow(base_len, pos) != 0 && pos < base_len)
		pos++;
	pos = pos + (n < 1 ? 1 : 0);
	if (!(res = (char *)easymalloc(sizeof(*res) * (pos + 1))))
		return (NULL);
	res[pos] = '\0';
	res[0] = n < 0 ? '-' : 0;
	res[0] = n ? res[0] : '0';
	while (pos > 0 && n != 0)
	{
		res[pos - 1] = base_to[(n < 0 ? -(n % base_len) : n % base_len)];
		n /= base_len;
		pos--;
	}
	return (res);
}