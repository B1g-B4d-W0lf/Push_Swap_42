/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/02/16 02:06:03 by wfreulon         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*lstb;

	lstb = NULL;
	lst = sora(argc, argv);
	printlst(lst);
	pusha(&lst, &lstb);
	doublepush(lst, lstb);
	printlst(lst);
	printf("--\n");
	printlst(lstb);
	clearlst(&lst);
	clearlst(&lstb);
	return (0);
}
