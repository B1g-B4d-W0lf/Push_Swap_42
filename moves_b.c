#include "push_swap.h"

void	swapb(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	temp->content = lst->content;
	lst->content = lst->next;
	lst->next = temp->content;
	return ;
}

void	pushb(t_list *lstb, t_list *lsta)
{
	ft_lstadd_front(&lstb, lsta);
	lsta->content = NULL;
	free(lsta);
	return ;
}

void	rotateb(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	ft_lstadd_back(&lst, temp);
	lst->content = NULL;
	free(lst);
	return ;
}

void	reverserb(t_list *lst)
{
	t_list	*temp;

	temp = ft_lstlast(lst);
	ft_lstadd_front(&lst, temp);
	lst = ft_lstlast(lst);
	lst->content = NULL;
	free(lst);
	return ;
}