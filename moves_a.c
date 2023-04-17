/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:41 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/17 02:34:50 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	ft_lstadd_front(lst, temp);
	ft_printf("sa\n");
	return ;
}

void	pusha(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (ft_lstsize(*lstb) < 1)
		return ;
	temp = *lstb;
	*lstb = (*lstb)->next;
	ft_lstadd_front(lsta, temp);
	ft_printf("pa\n");
	return ;
}

void	rotatea(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
	ft_printf("ra\n");
	return ;
}

void	reversera(t_list **lst)
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
	ft_printf("rra\n");
	return ;
}
