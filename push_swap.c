/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/12 02:40:06 by wfreulon         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*lstb;

	if (argc == 1)
		exit(0);
	lstb = NULL;
	lst = string(argc, argv);
	finalcheck(lst);
	sort(&lst, &lstb);
	clearlst(&lstb);
	clearlst(&lst);
	return (0);
}
