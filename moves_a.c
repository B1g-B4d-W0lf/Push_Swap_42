#include "push_swap.h"

void	swapa(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	temp->content = lst->content;
	lst->content = lst->next;
	lst->next = temp->content;
	return ;
}

void	pusha(t_list *lsta, t_list *lstb)
{
	ft_lstadd_front(&lsta, lstb);
	lstb->content = NULL;
	free(lstb);
	return ;
}

void	rotatea(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	ft_lstadd_back(&lst, temp);
	lst->content = NULL;
	free(lst);
	return ;
}

void	reversera(t_list *lst)
{
	t_list	*temp;

	temp = ft_lstlast(lst);
	ft_lstadd_front(&lst, temp);
	lst = ft_lstlast(lst);
	lst->content = NULL;
	free(lst);
	return ;
}