#include "push_swap.h"

void	printlst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	ft_printf("----\n");
	return ;
}
