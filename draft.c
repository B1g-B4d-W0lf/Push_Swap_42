/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:09:57 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/10 01:20:44 by wfreulon         ###   ########.fr       */
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
	if (sizeb/2 >= findpos(*lstb, moving) && sizea/2 >= findpos(*lst, sup))
	{
		while ((moving != (*lstb)->content || sup != (*lst)->content) 
			&& ((*lstb)->content != moving && (*lst)->content != sup))
			doublerotate(lst, lstb);
		while (moving != (*lstb)->content)
			rotateb(lstb);
		while (sup != (*lst)->content)
			rotatea(lst);
		pusha(lst, lstb);
	}
	else if (sizeb/2 <= findpos(*lstb, moving) && sizea/2 <= findpos(*lst, sup))
	{
		while ((moving != (*lstb)->content || sup != (*lst)->content)
			&& ((*lstb)->content != moving && (*lst)->content != sup))
			doublereverser(lst, lstb);
		while (moving != (*lstb)->content)
			reverserb(lstb);
		while (sup != (*lst)->content)
			reversera(lst);
		pusha(lst, lstb);
	}
	else if (sizeb/2 >= findpos(*lstb, moving) && sizea/2 <= findpos(*lst, sup))
	{
		while (moving != (*lstb)->content)
			rotateb(lstb);
		while (sup != (*lst)->content)
			reversera(lst);
		pusha(lst, lstb);
	}
	else if (sizeb/2 <= findpos(*lstb, moving) && sizea/2 >= findpos(*lst, sup))
	{
		while (moving != (*lstb)->content)
			reverserb(lstb);
		while (sup != (*lst)->content)
			rotatea(lst);
		pusha(lst, lstb);
	}	
}

void	lastmoves(t_list **lst)
{
	int	min;

	min = findmin(*lst);
	if (findpos(*lst, min) >= ft_lstsize(*lst))
	{
		while ((*lst)->content != min)
			reversera(lst);
	}
	else if (findpos(*lst, min) <= ft_lstsize(*lst))	
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
	{
		pushb(lst, lstb);
		pushb(lst, lstb);
		emptya(lst, lstb);
	}
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
}
