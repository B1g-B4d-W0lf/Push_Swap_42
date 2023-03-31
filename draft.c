/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:09:57 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/01 01:05:13 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moveit(t_list **lst, t_list **lstb, int i, int j)
{
	if ((*lstb)->content != i)
	{
		while ((*lstb)->content != i)
			rotateb(lstb);
	}
	if ((*lstb)->content == i)
	{
		while ((*lst)->content != j)
			rotatea(lst);
		pushb(lst, lstb);
	}
	return ;
}

void	triplereverse(t_list **lst)
{
	reversera(lst);
	reversera(lst);
	reversera(lst);
}

void	finalmove(t_list **lst, t_list **lstb, int i, int j)
{
	while (*lstb)
	{
		if ((*lstb)->content == findmax(*lstb) && (*lstb)->content > i)
			pusha(lst, lstb);
		if ((*lstb) && (*lstb)->content == findmax(*lstb)
			&& (*lstb)->content < j)
		{
			if (i == ft_lstlast(*lst)->content)
				triplereverse(lst);
			pusha(lst, lstb);
		}
		if ((!*lstb) && (*lst)->content != j && i == ft_lstlast(*lst)->content)
			triplereverse(lst);
		else
		{
			while ((*lstb) && (*lstb)->content != findmax(*lstb))
				rotateb(lstb);
		}
	}
	return ;
}

void	cheapest(t_list **lst, t_list **lstb)
{
	int		i;
	int		j;

	while (ft_lstsize(*lst) > 3)
	{
		i = diffint(*lst, findmax(*lstb));
		j = diffint(*lst, findmin(*lstb));
		if (compare(i, findmax(*lstb)) <= compare(j, findmin(*lstb)))
			moveit(lst, lstb, findmax(*lstb), i);
		else if (compare(i, findmax(*lstb)) >= compare(j, findmin(*lstb)))
			moveit(lst, lstb, findmin(*lstb), j);
	}
}

void	sort(t_list **lst, t_list **lstb)
{
	if (ft_lstsize(*lst) > 3)
	{
		pushb(lst, lstb);
		pushb(lst, lstb);
		cheapest(lst, lstb);
	}
	if (ft_lstsize(*lst) == 3)
	{
		if ((*lst)->content == findmax(*lst)
			&& ft_lstlast(*lst)->content == findmin(*lst))
			swapa(lst);
		if ((*lst)->content == findmin(*lst)
			&& (*lst)->next->content == findmax(*lst))
			swapa(lst);
		if ((*lst)->next->content == findmin(*lst)
			&& (*lst)->content == findmax(*lst))
			rotatea(lst);
		if ((*lst)->next->content == findmax(*lst)
			&& ft_lstlast(*lst)->content == findmin(*lst))
			reversera(lst);
		if ((*lst)->next->content == findmin(*lst)
			&& ft_lstlast(*lst)->content == findmax(*lst))
			swapa(lst);
		if ((*lst)->content == findmin(*lst)
			&& ft_lstlast(*lst)->content == findmax(*lst))
			finalmove(lst, lstb, findmax(*lst), findmin(*lst));
		return ;
	}
}
