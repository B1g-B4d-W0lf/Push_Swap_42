/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabgestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:47:13 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 22:24:37 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lsttotab(t_list *lst, int *tab)
{
	int	i;

	i = 0;
	while (lst)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
}

int	checktab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < size)
	{
		if (tab[i] > tab[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	bubblesort(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (checktab(tab, size) == 0)
	{
		if (j < size && tab[i] > tab[j])
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
		else
		{
			i++;
			j++;
		}
		if (i == size)
		{
			i = 0;
			j = 1;
		}
	}
}

void	emptya(t_list **lst, t_list **lstb)
{
	int	mediane;
	int	*tab;
	int	size;

	while (ft_lstsize(*lst) > 3)
	{
		size = ft_lstsize(*lst);
		tab = malloc((size) * sizeof(int));
		if (!tab)
			printerror(lst, 0, 0, lstb);
		lsttotab(*lst, tab);
		bubblesort(tab, size);
		mediane = tab[size / 2];
		free(tab);
		if ((*lst)->content >= mediane && findmax(*lst) >= mediane)
			pushb(lst, lstb);
		else if (findmax(*lst) <= mediane)
			pushb(lst, lstb);
		else
			rotatea(lst);
	}
}
