
#include "libft.h"
#include <stdlib.h>

int		ft_lstmap(t_head *head, t_lstmap_func func)
{
	int		check_ret;
	t_lst	*lst;
	t_lst	*tmp;

	lst = head->first;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if ((check_ret = func(head, tmp)) != EXIT_SUCCESS)
			return (check_ret);
	}
	return (EXIT_SUCCESS);
}
