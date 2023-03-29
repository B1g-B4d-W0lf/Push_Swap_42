/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/03/29 02:55:49 by wfreulon         ###   ########.fr       */
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

void	moveit(t_list **lst, t_list **lstb, int i, int j)
{
	if ((*lstb)->content != i)
	{
		while ((*lstb)->content != i)
			rotateb(lstb);
	}
	if ((*lstb)->content == i)
	{
		while((*lst)->content != j)
			rotatea(lst);
		pushb(lst, lstb);
	}
}

void	finalmove(t_list **lst, t_list **lstb)
{
	while(*lstb)
	{
		if ((*lstb)->content == findmax(*lstb))
			pusha(lst, lstb);
		else
		{
			while((*lstb)->content != findmax(*lstb))
				rotateb(lstb);
		}
	}
}
void	cheapest(t_list **lst, t_list **lstb)
{
	int		i;
	int		j;
	
	while(ft_lstsize(*lst) > 3)
	{
		i = diffint(*lst, findmax(*lstb));
		j = diffint(*lst, findmin(*lstb));
		if (compare(i, findmax(*lstb)) <= compare(j, findmin(*lstb)))
			moveit(lst, lstb, findmax(*lstb), i);
		else if (compare(i, findmax(*lstb)) >= compare(j, findmin(*lstb)))
			moveit(lst, lstb, findmin(*lstb), j);
	}
}

void	sort(t_list **lst, t_list **lstb)
{
	if (ft_lstsize(*lst) > 3)
	{
		pushb(lst, lstb);
		pushb(lst, lstb);
		cheapest(lst,lstb);
	}
	if (ft_lstsize(*lst) <= 3)
	{
		if ((*lst)->content == findmin(*lst) && (*lst)->next->content == findmax(*lst))
			swapa(lst);
		if ((*lst)->next->content == findmin(*lst) && (*lst)->content == findmax(*lst))
			rotatea(lst);
		if ((*lst)->next->content == findmax(*lst) && ft_lstlast(*lst)->content == findmin(*lst))
			reversera(lst);
		if ((*lst)->content == findmin(*lst) && ft_lstlast(*lst)->content == findmax(*lst))
			finalmove(lst, lstb);
		return;
	}
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

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*lstb;

	lstb = NULL;
	lst = sora(argc, argv);
	sort(&lst, &lstb);
	printlst(lst);
	printlst(lstb);
	clearlst(&lstb);
	clearlst(&lst);
	return (0);
}
