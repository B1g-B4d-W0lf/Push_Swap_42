/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:45 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/17 02:34:24 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doubleswap(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (ft_lstsize(*lsta) < 2 || ft_lstsize(*lstb) < 2)
		return ;
	temp = (*lsta)->next;
	(*lsta)->next = temp->next;
	ft_lstadd_front(lsta, temp);
	temp = (*lstb)->next;
	(*lstb)->next = temp->next;
	ft_lstadd_front(lstb, temp);
	ft_printf("ss\n");
	return ;
}

void	doublerotate(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (ft_lstsize(*lsta) < 2 || ft_lstsize(*lstb) < 2)
		return ;
	temp = *lsta;
	*lsta = (*lsta)->next;
	temp->next = NULL;
	ft_lstadd_back(lsta, temp);
	temp = *lstb;
	*lstb = (*lstb)->next;
	temp->next = NULL;
	ft_lstadd_back(lstb, temp);
	ft_printf("rr\n");
	return ;
}

void	doublereverser(t_list **lsta, t_list **lstb)
{
	t_list	*temp;
	t_list	*tmp;

	if (ft_lstsize(*lsta) < 2 || ft_lstsize(*lstb) < 2)
		return ;
	tmp = *lsta;
	temp = ft_lstlast(*lsta);
	while (tmp->next != temp)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lsta, temp);
	tmp = *lstb;
	temp = ft_lstlast(*lstb);
	while (tmp->next != temp)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lstb, temp);
	ft_printf("rrr\n");
	return ;
}
