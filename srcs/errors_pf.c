/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:39:28 by skpn              #+#    #+#             */
/*   Updated: 2020/02/11 11:01:32 by skpn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

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

void    set_errors_pf(t_error_tab *tab)
{
    tab->error[USER_ERRORS_START] = "No type given\n";
    tab->error[USER_ERRORS_START + 1] = "Unknown type given\n";
    tab->error[USER_ERRORS_START + 2] = "PF_BUF must be at least two\n";
}

int     print_error_pf(t_pf *pf, int error)
{
    t_error_tab tab;

    ft_set_lib_error_tab(&tab);
    set_errors_pf(&tab);
    write(1, tab.error[error], ft_strlen(tab.error[error]));
    exit_pf(pf);
    return (EXIT_FAILURE);
}