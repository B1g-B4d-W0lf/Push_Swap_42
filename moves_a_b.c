#include "push_swap.h"

void	doubleswap(t_list *lsta, t_list *lstb)
{
		t_list	*temp;

	temp = lsta;
	temp->content = lsta->content;
	lsta->content = lsta->next;
	lsta->next = temp->content;
	temp = lstb;
	temp->content = lstb->content;
	lstb->content = lstb->next;
	lstb->next = temp->content;
	return ;
}

void	doublepush(t_list *lsta, t_list *lstb)
{
	t_list	*temp;
	temp = lstb;
	temp->content = lstb->content;
	lstb->content = lsta->content;
	lsta->content = temp->content;
	return ;
}

void	doublerotate(t_list *lsta, t_list *lstb)
{
	t_list	*temp;

	temp = lsta;
	ft_lstadd_back(&lsta, temp);
	lsta->content = NULL;
	free(lsta);
	temp = lstb;
	ft_lstadd_back(&lstb, temp);
	lstb->content = NULL;
	free(lstb);
	return ;
}

void	doublereverser(t_list *lsta, t_list *lstb)
{
	t_list	*temp;

	temp = ft_lstlast(lsta);
	ft_lstadd_front(&lsta, temp);
	lsta = ft_lstlast(lsta);
	lsta->content = NULL;
	free(lsta);
	temp = ft_lstlast(lstb);
	ft_lstadd_front(&lstb, temp);
	lstb = ft_lstlast(lstb);
	lstb->content = NULL;
	free(lstb);
	return ;
}