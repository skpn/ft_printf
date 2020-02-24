/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:39:28 by skpn              #+#    #+#             */
/*   Updated: 2020/02/21 15:01:31 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

# define ERROR_NO_TYPE_MSG "No type given\n"

int     print_error_pf(int error)
{
    t_error_tab *tab;

    if (ft_set_error_tab(&tab, 2) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    // set_errors_pf(&tab);
    if (ft_set_user_error(tab, ERROR_NO_TYPE, "No type given\n")
            == EXIT_FAILURE
        || ft_set_user_error(tab, ERROR_NO_TYPE, ERROR_NO_TYPE_MSG)
            == EXIT_FAILURE
        || ft_set_user_error(tab, ERROR_BAD_TYPE, "Bad type given\n")
            == EXIT_FAILURE
        || ft_set_user_error(tab, ERROR_PF_BUF_TOO_SMALL
            , "PF_BUF must be at least 2\n") == EXIT_FAILURE
        || ft_set_user_error(tab, ERROR_TOO_MANY_PF_ARGS
            , "Too many data conversions\n") == EXIT_FAILURE
        || ft_set_user_error(tab, ERROR_PF_RESULT_TOO_LONG
            , "Result too long\n") == EXIT_FAILURE)
        return (EXIT_FAILURE);
    write(1, tab->error[error], sizeof(tab->error[error]));
    ft_free_error_tab(tab);
    return (EXIT_FAILURE);
}