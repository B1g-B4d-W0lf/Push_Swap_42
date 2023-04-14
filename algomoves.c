/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algomoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:03:00 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 02:48:01 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bothinf(t_list **lst, t_list **lstb, int moving, int sup)
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

void	bothsup(t_list **lst, t_list **lstb, int moving, int sup)
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

void	infsup(t_list **lst, t_list **lstb, int moving, int sup)
{
	while (moving != (*lstb)->content)
		rotateb(lstb);
	while (sup != (*lst)->content)
		reversera(lst);
	pusha(lst, lstb);
}

void	supinf(t_list **lst, t_list **lstb, int moving, int sup)
{
	while (moving != (*lstb)->content)
		reverserb(lstb);
	while (sup != (*lst)->content)
		rotatea(lst);
	pusha(lst, lstb);
}
