/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:20:38 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/22 02:28:48 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*plusisnull(char *argv)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	final = malloc(sizeof(char) * ft_strlen(argv));
	if (!final)
		return (NULL);
	i++;
	while (argv[i])
	{
		final[j] = argv[i];
		j++;
		i++;
	}
	final[j] = '\0';
	return (free(argv), final);
}

int	checkbis(char *argv, char *k)
{
	int	i;

	i = 0;
	if (argv[i] == '+')
		argv = plusisnull(argv);
	while (argv[i] && k[i] && (argv[i] == k[i]))
		i++;
	if (argv[i] != 0 || k[i] != 0)
		return (free(k), 0);
	return (1);
}

int	checkdigits(char *argv)
{
	int	i;

	i = 0;
	if (argv [i] == '+' || argv[i] == '-')
			i++;
	if (argv[i] < '0' || argv[i] > '9')
		return (0);
	while (argv[i] != 0)
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	finalcheck(t_list *lst)
{
	int		i;
	int		j;
	t_list	*temp;
	t_list	*head;

	if (ft_lstsize(lst) < 1)
		exit (0);
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
