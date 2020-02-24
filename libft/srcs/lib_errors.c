/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:55:14 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/23 17:18:29 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_print_error_tab(t_error_tab *tab)
{
	unsigned	error_nb;

	while (error_nb < MAX_ERROR)
	{
		if (tab->error[error_nb] != NULL)
			write(tab->fd, tab->error[error_nb], ft_strlen(tab->error[error_nb]));
		++error_nb;
	}
}

void	ft_free_error_tab(t_error_tab *tab)
{
	easyfree((void **)&tab);
}

int		set_error(t_error_tab *tab, unsigned error_nb, char *msg)
{
	unsigned	len;

	if ((len = ft_strlen(msg)) > MAX_ERROR_LENGTH)
		len = MAX_ERROR_LENGTH;
	if (error_nb >= MAX_ERROR)
		return (ERROR_ERROR_NUMBER_TOO_HIGH);
	if (error_nb == EXIT_SUCCESS)
		return (ERROR_ERROR_NUMBER_IS_EXIT_SUCCESS);
	if (tab->error[error_nb] != NULL)
		return (ERROR_ERROR_NUMBER_UNAVAILABLE);
	ft_memcpy(tab->error[error_nb], msg, len);
	if (error_nb > tab->highest_error)
		++(tab->highest_error);
	return (EXIT_SUCCESS);
}

int		ft_set_user_error(t_error_tab *tab, unsigned error_nb, char *msg)
{
	return (set_error(tab, error_nb + tab->user_errors_start, msg));
}

int		ft_set_error_tab(t_error_tab **target_tab, unsigned fd)
{
	t_error_tab	*tab;

	if (!(tab = (t_error_tab *)easymalloc(sizeof(*tab))))
	{
		write(fd, "Could not allocate error tab\n"
			, sizeof("Could not allocate error tab\n"));
		return (EXIT_FAILURE);
	}
	ft_memset(tab, 0, sizeof(*tab));
	tab->fd = fd;
	set_error(tab, ERROR_MALLOC, "Malloc error\n");
	set_error(tab, ERROR_OPEN_FD, "Unable to open file\n");
	set_error(tab, ERROR_READ,"Unable to read\n");
	set_error(tab, ERROR_D_ARRAY_SIZE,"Error with d_array\n");
	set_error(tab, ERROR_MAGIC_FILE,"Magic file error\n");
	set_error(tab, ERROR_WITHOUT_MSG,"");
	set_error(tab, ERROR_ERROR_NUMBER_TOO_HIGH, "Error tab full\n");
	set_error(tab, ERROR_ERROR_NUMBER_IS_EXIT_SUCCESS
		, "Error number_is_exit_success");
	*target_tab = tab;
	return (EXIT_SUCCESS);
}
