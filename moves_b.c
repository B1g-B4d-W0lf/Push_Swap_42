/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:37 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/17 02:35:30 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapb(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	ft_lstadd_front(lst, temp);
	ft_printf("sb\n");
	return ;
}

void	pushb(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (ft_lstsize(*lsta) < 1)
		return ;
	temp = *lsta;
	*lsta = (*lsta)->next;
	ft_lstadd_front(lstb, temp);
	ft_printf("pb\n");
	return ;
}

void	rotateb(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
	ft_printf("rb\n");
	return ;
}

void	reverserb(t_list **lst)
{
	t_list	*temp;
	t_list	*tmp;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	temp = ft_lstlast(*lst);
	while (tmp->next != temp)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst, temp);
	ft_printf("rrb\n");
	return ;
}
