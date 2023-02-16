/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:32:35 by wfreulon          #+#    #+#             */
/*   Updated: 2023/02/15 23:43:00 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkargv(int argc, char **argv, int i)
{
	int	j;
	int	k;
	int	l;

	j = i + 1;
	while (i != argc)
	{
		k = ft_atoi(argv[i]);
		while (j != argc)
		{
			l = ft_atoi(argv[j]);
			if (k == l)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

t_list	*string(char *arg)
{
	t_list	*tab;
	char	**temp;
	int		str;
	int		i;

	tab = NULL;
	temp = ft_split(arg, ' ');
	i = 0;
	while (temp[i] != NULL)
		i++;
	if (checkargv(i, temp, 0) == 0)
		printerror();
	i = 0;
	while (temp[i] != NULL)
	{
		str = ft_atoi(temp[i]);
		ft_lstadd_back(&tab, ft_lstnew(str));
		i++;
	}
	return (tab);
}

t_list	*array(int argc, char **argv)
{
	t_list	*tab;
	int		i;
	int		j;

	tab = NULL;
	i = 1;
	if (checkargv(argc, argv, 1) == 0)
		printerror();
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_lstadd_back(&tab, ft_lstnew(j));
		i++;
	}
	return (tab);
}

t_list	*sora(int argc, char **argv)
{
	t_list	*lst;

	if (argc == 2)
		lst = string(argv[1]);
	else if (argc > 2)
		lst = array(argc, argv);
	printf("c bon ou c pa bon\n");
	return (lst);
}