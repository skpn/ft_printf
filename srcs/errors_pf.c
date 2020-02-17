/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:39:28 by skpn              #+#    #+#             */
/*   Updated: 2020/02/13 10:37:07 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
void    free_pf_arg(t_pf_arg **arg)
{
    if ((*arg)->malloc_str)
    {
        printf("freeing\n");
        easyfree((void **)&(*arg)->malloc_str);
    }
    easyfree((void **)arg);
}

void    exit_pf(t_pf *pf)
{
    t_lst   *elem;

    if (pf->args.first)
    {
        elem = pf->args.first;
        while (elem)
        {
            free_pf_arg((t_pf_arg **)&elem->content);
            if (elem->prev)
                easyfree((void **)&elem->prev);
            elem = elem->next;
        }
        easyfree((void **)&pf->args.last);
    }
    if (pf->result)
        easyfree((void **)pf->result);
}
*/

void    set_errors_pf(t_error_tab *tab)
{
    set_user_error(tab, ERROR_NO_TYPE, "No type given\n");
    set_user_error(tab, ERROR_BAD_TYPE, "Bad type given\n");
    set_user_error(tab, ERROR_PF_BUF_TOO_SMALL, "PF_BUF must be at least 2\n");
    set_user_error(tab, ERROR_TOO_MANY_PF_ARGS, "Too many data conversions\n");
}

int     print_error_pf(t_pf *pf, int error)
{
    t_error_tab tab;

    ft_set_error_tab(&tab);
    set_errors_pf(&tab);
    write(1, tab.error[error], ft_strlen(tab.error[error]));
    exit_pf(pf);
    return (EXIT_FAILURE);
}