/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:37:34 by wfreulon          #+#    #+#             */
/*   Updated: 2023/03/29 01:26:36 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmax(t_list *lst)
{
	int	i;

	i = lst->content;
	while (lst != NULL)
	{
		if (lst->content > i)
			i = lst->content;
		lst = lst->next;
	}
	return (i);
}

int	findmin(t_list *lst)
{
	int	i;

	i = lst->content;
	while (lst != NULL)
	{
		if (lst->content < i)
			i = lst->content;
		lst = lst->next;
	}
	return (i);
}

int	diffint(t_list *lst, int i)
{
	int	j;
	int	k;
	int	fin;

	k = 0;
	if (lst->content > i)
		k = lst->content - i;
	else if (lst->content < i)
		k = i - lst->content;
	fin = lst->content;
	lst = lst->next;
	while(lst)
	{
		if (lst->content > i)
			j = lst->content - i;
		else if (lst->content < i)
			j = i - lst->content;
		if (j <= k)
		{
			fin = lst->content;
			k = j;
		}
		lst = lst->next;
	}
	return (fin);
}

int	compare(int i, int j)
{
	int	diff;
	
	if (i > j)
		diff = i - j;
	else if (i < j)
		diff = j - i;
	return (diff);
}
