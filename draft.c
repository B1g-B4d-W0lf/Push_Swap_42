/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:09:57 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/05 23:00:41 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	/*if ((*lst)->content == findmin(*lst)
		&& ft_lstlast(*lst)->content == findmax(*lst))
		finalmove(lst, lstb, findmax(*lst), findmin(*lst));*/
}

void	sort(t_list **lst, t_list **lstb)
{
	if (ft_lstsize(*lst) > 3)
	{
		pushb(lst, lstb);
		pushb(lst, lstb);
		emptya(lst, lstb);
	}
	if (ft_lstsize(*lst) == 3)
	{
		sortthree(lst);
		whileit(*lst, *lstb);
		return ;
	}
}
