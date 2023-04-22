/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:49:20 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/21 23:28:04 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	printerror(t_list **lst, char **tab, char *str, t_list **lstb)
{
	if (lst)
		clearlst(lst);
	if (lstb)
		clearlst(lstb);
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
	char	*moves;

	if (argc == 1)
		exit(0);
	lstb = NULL;
	lst = string(argc, argv);
	finalcheck(lst);
	moves = get_next_line(0);
	while (moves != NULL)
	{
		applymoves(&lst, &lstb, moves);
		free(moves);
		moves = get_next_line(0);
	}
	if (lstb == NULL && checking(lst) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clearlst(&lst);
	clearlst(&lstb);
	return (0);
}
