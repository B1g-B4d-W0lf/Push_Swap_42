/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:01:32 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/11 02:03:25 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findpos(t_list *lst, int i)
{
	int	index;

	index = 0;
	while (lst && lst->content != i)
	{
		index++;
		lst = lst->next;
	}
	return (index);
}

int	findsup(t_list *lst, int i, int diff, int fin)
{
	int	temp;

	while (lst)
	{
		if (lst->content > i)
			temp = lst->content - i;
		else if (lst->content < i)
			temp = i - lst->content;
		if (temp <= diff && lst->content > i)
		{
			fin = lst->content;
			diff = temp;
		}
		lst = lst->next;
	}
	return (fin);
}

int	supone(t_list *lst, int i)
{
	int		diff;
	int		fin;
	t_list	*backup;

	backup = lst;
	while (lst && lst->content < i)
		lst = lst->next;
	if (!lst)
		fin = findmin(backup);
	if (lst && lst->content > i)
	{
		diff = lst->content - i;
		fin = lst->content;
	}
	fin = findsup(lst, i, diff, fin);
	return (fin);
}

int	calculate(t_list *lst, t_list *lstb, int current, int sup)
{
	int	total;
	int	sizea;
	int	sizeb;

	sizea = ft_lstsize(lst);
	sizeb = ft_lstsize(lstb);
	if (sizeb / 2 >= findpos(lstb, current)
		&& sizea / 2 >= findpos(lst, sup))
		total = firstop(lst, lstb, current, sup);
	else if (sizeb / 2 <= findpos(lstb, current)
		&& sizea / 2 <= findpos(lst, sup))
		total = secondop(lst, lstb, current, sup);
	else if (sizea / 2 >= findpos(lst, sup)
		&& sizeb / 2 <= findpos(lstb, current))
		total = thirdop(lst, lstb, current, sup);
	else if (sizea / 2 <= findpos(lst, sup)
		&& sizeb / 2 >= findpos(lstb, current))
		total = fourthop(lst, lstb, current, sup);
	return (total);
}

int	whileit(t_list *lst, t_list *lstb)
{
	int		sup;
	int		moves;
	int		lowest;
	int		needed;
	t_list	*temp;

	temp = lstb;
	needed = lstb->content;
	lowest = 2147483647;
	while (lstb)
	{
		sup = supone(lst, lstb->content);
		moves = calculate(lst, temp, lstb->content, sup);
		if (moves < lowest && lstb)
		{
			lowest = moves;
			needed = lstb->content;
		}
		lstb = lstb->next;
	}
	return (needed);
}
