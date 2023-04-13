/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 00:49:47 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printerror(t_list **lst, char **tab, char *str)
{
	if (lst)
		clearlst(lst);
	if (tab)
		freetab(tab);
	if (str)
		free(str);
	ft_printf("Error\n");
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

int	checking(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	lst = lst->next;
	while (lst)
	{
		if (temp->content > lst->content)
			return (0);
		lst = lst->next;
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*lstb;

	if (argc == 1)
		exit(0);
	lstb = NULL;
	lst = string(argc, argv);
	finalcheck(lst);
	if (checking(lst) == 0)
		sort(&lst, &lstb);
	clearlst(&lstb);
	clearlst(&lst);
	return (0);
}
