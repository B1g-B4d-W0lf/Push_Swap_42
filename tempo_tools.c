/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:05:09 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/01 01:23:59 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*int	median(t_list *lst)
{
	int		i;
	int 	j;
	int		k;

	i = ft_lstsize(lst) / 2;
	j = 0;
	while (j < i)
	{
		j++;
		lst = lst->next;
		k = lst->content;
		
	}
	return (k);
}*/
