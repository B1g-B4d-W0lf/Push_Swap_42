#include "push_swap.h"

void	clearlst(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{	
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(lst);
	}
	return ;
}

int	checkargv(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 1;
	j = i + 1;
	while(i != argc)
	{
		k = ft_atoi(argv[i]);
		while(j != argc)
		{
			l = ft_atoi(argv[j]);
			if(k == l)
				return(0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return(1);
}

t_list	**string(char *arg)
{
	t_list	**tab;
	char	**temp;
	int		*str;
	int		i;

	temp = ft_split(arg, ' ');
	i = 0;
	str = malloc(sizeof(int));
	if(!str)
		free(str);
	while(temp[i] != NULL)
	{
		*str = ft_atoi(temp[i]);
		printf("%d\n", *str);
		ft_lstadd_back(tab, ft_lstnew(str));
		if(!tab || !*tab)
			free(tab);
		i++;
	}
	free(str);
	return (tab);
}

t_list	**array(int argc, char **argv)
{
	t_list	**tab;
	int		i;
	int		*j;

	i = 1;
	j = malloc(sizeof(int));
	if (!j)
		free(j);
	while(i <= argc)
	{
		*j = ft_atoi(argv[i]);
		printf("%d\n", *j);
		ft_lstadd_back(tab, ft_lstnew(j));
		if(!tab || !*tab)
			free(tab);
		printf("%d\n", (*tab)->content);
		i++;
	}
	free(j);
	return (tab);
}

int	main(int argc, char **argv)
{
	t_list	**lst;

	if (checkargv(argc, argv) == 0)
	{
		ft_printf("ERROR BITCH\n");
		return(0);
	}
	else if(argc > 2)
		lst = array(argc, argv);
	else if(argc == 2)
		lst = string(argv[1]);
	clearlst(lst);
	ft_printf("%d\n", (*lst)->content);
	return (0);
}
