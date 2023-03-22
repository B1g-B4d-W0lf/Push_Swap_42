/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/03/22 23:09:49 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printerror(void)
{
	ft_printf("ERROR BITCH TRY AGAIN");
	exit(0);
}

void	clearlst(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{	
		temp = *lst;
		*lst = (*lst)->next;
		temp->content = 0;
		free(temp);
	}
	return ;
}

void	sort(t_list *lst)
{
	int		i;
	int		j;
	int		k;
	t_list	*temp;
	t_list	*tmp;
	
	temp = lst;
	tmp = lst;
	while(temp != NULL)
	{
		k = temp->content;
		while(lst != NULL && lst->content < k)
		{
			lst = lst->next;
		}
		j = lst->content;
		lst->content = k;
		temp->content = j;
		temp = temp->next;
		lst = tmp;
	}
}

int	median(t_list *lst)
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
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*lstbis;

	lst = sora(argc, argv);
	lstbis = sora(argc, argv);
	sort2(&lstbis);
	printlst(lst);
	printlst(lstbis);
	clearlst(&lstbis);
	clearlst(&lst);
	return (0);
}
