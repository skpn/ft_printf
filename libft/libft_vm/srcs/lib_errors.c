/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:55:14 by sikpenou          #+#    #+#             */
/*   Updated: 2020/01/29 16:47:10 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_lib_error_tab(t_error_tab *tab)
{
	tab->error[ERROR_MALLOC] = "Malloc error\n";
	tab->error[ERROR_OPEN_FD] = "Unable to open file\n";
	tab->error[ERROR_READ] = "Unable to read\n";
	tab->error[ERROR_D_ARRAY_SIZE] = "Error with d_array\n";
	tab->error[ERROR_MAGIC_FILE] = "Error with magic file\n";
	tab->error[ERROR_WITHOUT_MSG] = "";
	tab->max_error = MAX_ERROR;
	tab->user_errors_start = USER_ERRORS_START;
}
