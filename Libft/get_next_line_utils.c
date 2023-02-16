/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:40:26 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/21 01:32:04 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnewnew(char *content, t_lst *lst, int boolean)
{
	t_lst	*res;
	int		i;

	i = -1;
	if (!boolean)
	{
		if (lst == NULL)
			return (NULL);
		while (lst->next != NULL)
			lst = lst->next;
		res = lst;
		return (res);
	}
	res = malloc(sizeof(t_lst));
	if (!res)
		return (NULL);
	res->content = malloc(((ft_strlenfree(content, 0, 1) + 1) * sizeof(char)));
	if (!res->content)
		return (free(res), NULL);
	while (content[++i])
		res->content[i] = content[i];
	res->content[i] = '\0';
	res->next = NULL;
	return (res);
}

char	*ft_lstaddback(t_lst **lst, t_lst *new, char *west, int boolean)
{
	t_lst	*temp;

	if (!boolean)
	{
		if (new == NULL)
		{
			ft_strlenfree(0, *lst, 0);
			return (NULL);
		}
		if (lst && *lst)
		{
			temp = ft_lstnewnew(0, *lst, 0);
			temp->next = new;
		}
		else
			*lst = new;
		return (NULL);
	}
	free(west);
	west = NULL;
	return (west);
}

int	ft_strlenfree(char *str, t_lst *tab, int boolean)
{
	int		i;
	t_lst	*temp;

	i = 0;
	if (!boolean)
	{
		while (tab)
		{
			temp = tab;
			tab = tab->next;
			free(temp->content);
			free(temp);
		}
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

int	ft_lstiternew(t_lst *lst, int (*f)(char *, t_lst *tab, int boolean))
{
	int		index;

	index = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		index = index + (*f)(lst->content, 0, 1);
		lst = lst->next;
	}
	return (index);
}

int	checkbuffer(char c, char const *set)
{
	int		i;

	i = 0;
	if (!set)
		return (2);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
