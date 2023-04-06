/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:58:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/05 23:25:32 by wfreulon         ###   ########.fr       */
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
			if (i == ft_lstlast(*lst)->content
				&& (*lst)->content != j && j < (*lst)->content)
				triplereverse(lst);
			pusha(lst, lstb);
		}
		if ((!*lstb) && (*lst)->content != j && i == ft_lstlast(*lst)->content
			&& j < (*lst)->content)
			triplereverse(lst);
		else
		{
			while ((*lstb) && (*lstb)->content != findmax(*lstb))
				rotateb(lstb);
		}
	}
	return ;
}
