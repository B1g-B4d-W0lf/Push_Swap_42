/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:09:57 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 22:49:09 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	efficient(t_list **lst, t_list **lstb, int moving)
{
	int	sup;
	int	sizea;
	int	sizeb;

	sup = supone(*lst, moving);
	sizea = ft_lstsize(*lst);
	sizeb = ft_lstsize(*lstb);
	if (sizeb / 2 >= findpos(*lstb, moving)
		&& sizea / 2 >= findpos(*lst, sup))
		bothinf(lst, lstb, moving, sup);
	else if (sizeb / 2 <= findpos(*lstb, moving)
		&& sizea / 2 <= findpos(*lst, sup))
		bothsup(lst, lstb, moving, sup);
	else if (sizeb / 2 >= findpos(*lstb, moving)
		&& sizea / 2 <= findpos(*lst, sup))
		infsup(lst, lstb, moving, sup);
	else if (sizeb / 2 <= findpos(*lstb, moving)
		&& sizea / 2 >= findpos(*lst, sup))
		supinf(lst, lstb, moving, sup);
}

void	lastmoves(t_list **lst)
{
	int	min;
	int	size;
	int	pos;

	size = ft_lstsize(*lst);
	min = findmin(*lst);
	pos = findpos(*lst, min);
	if (pos >= size / 2)
	{
		while ((*lst)->content != min)
			reversera(lst);
	}
	else if (pos <= size / 2)
	{
		while ((*lst)->content != min)
			rotatea(lst);
	}
}

void	sortthree(t_list **lst)
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
}

void	sort(t_list **lst, t_list **lstb)
{
	int	moving;

	if (ft_lstsize(*lst) > 3)
		emptya(lst, lstb);
	if (ft_lstsize(*lst) == 3)
	{
		sortthree(lst);
		while (*lstb)
		{
			moving = whileit(*lst, *lstb);
			efficient(lst, lstb, moving);
		}
		lastmoves(lst);
	}
	if (ft_lstsize(*lst) < 3)
	{
		if (ft_lstsize(*lst) == 2
			&& (*lst)->content > (*lst)->next->content)
			swapa(lst);
	}
	return ;
}
