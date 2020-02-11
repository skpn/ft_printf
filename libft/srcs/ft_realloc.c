/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:43:11 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/11 09:33:30 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_realloc(void **zone, long curr_size, long to_add)
{
	char	*tmp;

	if (!(tmp = (char *)easymalloc(sizeof(char) * (curr_size + to_add))))
		return (0);
	ft_memcpy_heap(tmp, *zone, curr_size);
	easyfree(zone);
	*zone = tmp;
	return (curr_size + to_add);
}
