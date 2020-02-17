/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:55:14 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/13 10:33:39 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_set_user_error(t_error_tab *tab, unsigned error_nb, char *msg)
{
	if (error_nb + USER_ERRORS_START >= MAX_ERROR)
		return (ERROR_USER_ERROR_NUMBER_TOO_HIGH);
	tab->error[error_nb + USER_ERRORS_START] = msg;
	return (EXIT_SUCCESS);
}

void	ft_set_lib_error_tab(t_error_tab *tab)
{
	ft_memset(tab, 0, sizeof(*tab));
	tab->error[ERROR_MALLOC] = "Malloc error\n";
	tab->error[ERROR_OPEN_FD] = "Unable to open file\n";
	tab->error[ERROR_READ] = "Unable to read\n";
	tab->error[ERROR_D_ARRAY_SIZE] = "Error with d_array\n";
	tab->error[ERROR_MAGIC_FILE] = "Error with magic file\n";
	tab->error[ERROR_WITHOUT_MSG] = "";
	tab->error[ERROR_USER_ERROR_NUMBER_TOO_LOW]
		= "Error number reserved for lib errrors\n";
	tab->error[ERROR_USER_ERROR_NUMBER_TOO_HIGH]
		= "Error tab full\n";
	tab->max_error = MAX_ERROR;
	tab->user_errors_start = USER_ERRORS_START;
	tab->user_highest_error = USER_ERRORS_START;
}
