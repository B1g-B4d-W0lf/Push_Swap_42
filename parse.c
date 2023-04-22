/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:37:23 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/22 01:17:16 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*actualint(char *argv, int i, int size, char **arg)
{
	int		j;
	char	*temp;

	j = i;
	while (argv[i])
	{
		i++;
		size++;
	}
		i = j;
		j = 0;
	temp = malloc((size +1) * (sizeof(char)));
	if (!temp)
		printerror(0, arg, argv, 0);
	if (argv[0] == '-')
	{
		temp[j] = argv[0];
		j++;
	}
	while (argv[i])
		temp[j++] = argv[i++];
	temp [j] = '\0';
	return (temp);
}

char	*noextrazero(char *argv, char **arg)
{
	int		i;
	int		size;
	char	*temp;

	i = 0;
	size = 0;
	if (argv[0] == '-' || argv[0] == '+')
	{
		i++;
		size++;
		while (argv[i] == '0')
			i++;
	}
	else if (argv[0] == '0' && argv[1] != '\0')
		while (argv[i] == '0')
			i++;
	else if (argv[0] == '0' && argv[1] == '\0')
		size++;
	temp = actualint(argv, i, size, arg);
	return (temp);
}

int	checkargv(int argc, char **argv, int i)
{
	int		k;
	char	*result;
	char	*temp;

	while (i != argc)
	{
		if (checkdigits(argv[i]) == 0)
			return (0);
		k = ft_atoi(argv[i]);
		if (k != 0)
		{
			result = ft_itoa(k);
			temp = noextrazero(argv[i], argv);
			if (checkbis(temp, result) == 0)
				return (free (temp), 0);
			free(result);
			free (temp);
		}	
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
			printerror(&tab, temp, 0, 0);
		str[1] = 0;
		while (temp[str[1]] != NULL)
			littlekitten(str, &tab, temp);
		str[1] = 0;
		freetab(temp);
	}
	return (tab);
}
