/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:20:38 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/17 01:22:05 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdigits(char *argv, char *k, int bin)
{
	int	i;

	i = 0;
	if (bin == 0)
	{
		while (argv[i] != 0)
		{
			if (argv[i] >= '0' && argv[i] <= '9')
				i++;
			else if (argv [i] == '+' || argv[i] == '-')
				i++;
			else
				return (0);
		}
	}
	else if (bin == 1)
	{
		while (argv[i] && k[i] && (argv[i] == k[i]))
			i++;
		if (argv[i] != 0 || k[i] != 0)
			return (free(k), 0);
	}
	return (1);
}

void	finalcheck(t_list *lst)
{
	int		i;
	int		j;
	t_list	*temp;
	t_list	*head;

	temp = lst->next;
	head = lst;
	while (lst->next != NULL)
	{
		i = lst->content;
		while (temp)
		{
			j = temp->content;
			if (j == i)
			{
				printerror(&head, 0, 0, 0);
			}
			temp = temp->next;
		}
		lst = lst->next;
		temp = lst->next;
	}
}
