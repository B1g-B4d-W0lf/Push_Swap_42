/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:05:09 by wfreulon          #+#    #+#             */
/*   Updated: 2023/03/29 01:31:05 by wfreulon         ###   ########.fr       */
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
