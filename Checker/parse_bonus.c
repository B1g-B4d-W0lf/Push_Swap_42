/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:37:23 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/13 00:39:57 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
				printerror(&head, 0, 0);
			}
			temp = temp->next;
		}
		lst = lst->next;
		temp = lst->next;
	}
}

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
		while ((argv[i] && k[i]) && (argv[i] == k[i]))
			i++;
		if (argv[i] != 0 || k[i] != 0)
			return (free(k), 0);
	}
	return (1);
}

int	checkargv(int argc, char **argv, int i)
{
	int		k;
	char	*result;

	while (i != argc)
	{
		if (checkdigits(argv[i], 0, 0) == 0)
			return (0);
		k = ft_atoi(argv[i]);
		result = ft_itoa(k);
		if (checkdigits(argv[i], result, 1) == 0)
			return (0);
		free(result);
		i++;
	}
	return (1);
}

void	littlekitten(int *str, t_list **tab, char **temp)
{
	str[2] = ft_atoi(temp[str[1]]);
	ft_lstadd_back(tab, ft_lstnew(str[2]));
	str[1]++;
}

t_list	*string(int argc, char **argv)
{
	t_list	*tab;
	char	**temp;
	int		str[3];

	tab = NULL;
	str[0] = 1;
	str[1] = 0;
	while (str[0] != argc)
	{
		temp = ft_split(argv[str[0]], ' ');
		str[0]++;
		while (temp[str[1]] != NULL)
			str[1]++;
		if (checkargv(str[1], temp, 0) == 0)
			printerror(&tab, temp, 0);
		str[1] = 0;
		while (temp[str[1]] != NULL)
			littlekitten(str, &tab, temp);
		str[1] = 0;
		freetab(temp);
	}
	return (tab);
}
