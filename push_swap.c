/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/03/30 23:11:26 by wfreulon         ###   ########.fr       */
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
	// printlst(lst);
	// printlst(lstb);
	clearlst(&lstb);
	clearlst(&lst);
	return (0);
}
