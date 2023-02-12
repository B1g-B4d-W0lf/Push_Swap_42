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

t_list	*string(char *arg)
{
	t_list	*tab;
	char	**temp;
	int		str;
	int		i;

	tab = NULL;
	temp = ft_split(arg, ' ');
	i = 0;
	while(temp[i] != NULL)
		i++;
	if (!checkargv(i, temp))
		printerror();
	i = 0;
	while(temp[i] != NULL)
	{
		str = ft_atoi(temp[i]);
		printf("%d\n", str);
		ft_lstadd_back(&tab, ft_lstnew(str));
		printf("%d--\n", tab->content);
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
	while(i <= argc)
	{
		j = ft_atoi(argv[i]);
		printf("%d\n", j);
		ft_lstadd_back(&tab, ft_lstnew(j));
		printf("%d--\n", tab->content);
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	if (checkargv(argc, argv) == 0)
		printerror();
	else if(argc == 2)
		lst = string(argv[1]);
	else if(argc > 2)
		lst = array(argc, argv);	
	printf("c bon ou c pa bon\n");
	printf("%d\n", lst->content);
	clearlst(&lst);
	return (0);
}
