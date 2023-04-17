/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applying.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:07:29 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/17 02:46:12 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	printlst(t_list *lst)
{
	ft_printf("----\n");
	while (lst != NULL)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
	ft_printf("----\n");
	return ;
}

void	applynd(t_list **lst, t_list **lstb, char *moves, int size)
{
	if (ft_strncmp(moves, "rra\n", size) == 0)
		reversera(lst);
	else if (ft_strncmp(moves, "rrb\n", size) == 0)
		reverserb(lstb);
	else if (ft_strncmp(moves, "rrr\n", size) == 0)
		doublereverser(lst, lstb);
	else
		printerror(lst, 0, moves, lstb);
}

void	applymoves(t_list **lst, t_list **lstb, char *moves)
{
	size_t	size;

	size = ft_strlen(moves);
	if (ft_strncmp(moves, "ra\n", size) == 0)
		rotatea(lst);
	else if (ft_strncmp(moves, "rb\n", size) == 0)
		rotateb(lstb);
	else if (ft_strncmp(moves, "rr\n", size) == 0)
		doublerotate(lst, lstb);
	else if (ft_strncmp(moves, "sa\n", size) == 0)
		swapa(lst);
	else if (ft_strncmp(moves, "sb\n", size) == 0)
		swapb(lstb);
	else if (ft_strncmp(moves, "ss\n", size) == 0)
		doubleswap(lst, lstb);
	else if (ft_strncmp(moves, "pa\n", size) == 0)
		pusha(lst, lstb);
	else if (ft_strncmp(moves, "pb\n", size) == 0)
		pushb(lst, lstb);
	else if (size == 4)
		applynd(lst, lstb, moves, size);
	else
		printerror(lst, 0, moves, lstb);
}
