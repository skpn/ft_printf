/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_heap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:22:42 by skpn              #+#    #+#             */
/*   Updated: 2020/02/11 09:22:43 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy_heap(void *dst, const void *src, size_t n)
{
	long	*cpy_dst;
	long	*cpy_src;
	size_t	stop;

	cpy_dst = (long *)dst;
	cpy_src = (long *)src;
	if (n >= sizeof(long))
	{
		stop = n / sizeof(long);
		while (stop--)
			*cpy_dst++ = *cpy_src++;
		n %= sizeof(long);
	}
	while (n--)
		*(((char *)cpy_dst) + n) = *(((char *)cpy_src) + n);
	return (dst);
}
