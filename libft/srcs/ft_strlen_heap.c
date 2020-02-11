/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_heap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:22:09 by skpn              #+#    #+#             */
/*   Updated: 2020/02/11 09:26:33 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen_heap(char *str)
{
	long	*long_str;
	long	val;

	if (sizeof(str) != 8)
		return (sizeof(str));
	long_str = (long *)str;
	while ((val = *long_str) && (char)(val) && (char)(val >> 8)
		&& (char)(val >> 16) && (char)(val >> 24) && (char)(val >> 32)
		&& (char)(val >> 40) && (char)(val >> 48) && (char)(val >> 56))
		long_str++;
	if (!((char)(val)))
		return ((size_t)((char *)long_str - str));
	else if (!((char)(val >> 8)))
		return ((size_t)((char *)long_str - str + 1));
	else if (!((char)(val >> 16)))
		return ((size_t)((char *)long_str - str + 2));
	else if (!((char)(val >> 24)))
		return ((size_t)((char *)long_str - str + 3));
	else if (!((char)(val >> 32)))
		return ((size_t)((char *)long_str - str + 4));
	else if (!((char)(val >> 40)))
		return ((size_t)((char *)long_str - str + 5));
	else if (!((char)(val >> 48)))
		return ((size_t)((char *)long_str - str + 6));
	else
		return ((size_t)((char *)long_str - str + 7));
}
