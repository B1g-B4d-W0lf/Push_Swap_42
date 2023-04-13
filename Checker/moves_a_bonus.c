/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:46:08 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 00:34:52 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swapa(t_list **lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	ft_lstadd_front(lst, temp);
	return ;
}

void	pusha(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	temp = *lstb;
	*lstb = (*lstb)->next;
	ft_lstadd_front(lsta, temp);
	return ;
}

void	rotatea(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
	return ;
}

void	reversera(t_list **lst)
{
	t_list	*temp;
	t_list	*tmp;

	tmp = *lst;
	temp = ft_lstlast(*lst);
	while (tmp->next != temp)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst, temp);
	return ;
}
