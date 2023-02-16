/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:41 by wfreulon          #+#    #+#             */
/*   Updated: 2023/02/16 00:56:27 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	
	temp = *lsta;
	*lsta = (*lsta)->next;
	ft_lstadd_front(lstb, temp);
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
