/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seconddraft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:01:32 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/10 01:26:40 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findpos(t_list *lst, int i)
{
	int	index;
	
	index = 0;
	while(lst && lst->content != i)
	{
		index++;
		lst = lst->next;
	}
	return (index);
}

int	findsup(t_list *lst, int i, int	diff, int fin)
{
	int	temp;
	
	while (lst)
	{
		if (lst->content > i)
			temp = lst->content - i;
		else if (lst->content < i)
			temp = i - lst->content;
		if (temp <= diff && lst->content > i)
		{
			fin = lst->content;
			diff = temp;
		}
		lst = lst->next;
	}
	return (fin);
}

int	supone(t_list *lst, int i)
{
	int		diff;
	int		fin;
	t_list	*backup;

	backup = lst;
	while (lst && lst->content < i)
		lst = lst->next;
	if (!lst)
		fin = findmin(backup);
	if (lst && lst->content > i)
	{
		diff = lst->content - i;
		fin = lst->content;
	}
	fin = findsup(lst, i, diff, fin);
	return (fin);
}

int	calculate(t_list *lst, t_list *lstb, int current, int i)
{
	int		indexb;
	int		indexa;
	int		sizea;
	int		sizeb;

	indexb = 0;
	indexa = 0;
	sizea = ft_lstsize(lst);
	sizeb = ft_lstsize(lstb);
	if (sizeb/2 >= findpos(lstb, current) && sizea/2 >= findpos(lst, i))
	{
		indexb += findpos(lstb, current);
		indexa += findpos(lst, i);
		if (indexa > indexb)
			indexa = indexa - indexb;
		else if (indexa < indexb)
			indexb = indexb - indexa;
		else if (indexa == indexb)
			indexb = indexb - indexa;
	}
	else if (sizeb/2 <= findpos(lstb, current) && sizea/2 <= findpos(lst, i))
	{
		indexb += (sizeb - findpos(lstb, current));
		indexa += (sizea - findpos(lst, i));
		if (indexa > indexb)
			indexa = indexa - indexb;
		else if (indexa < indexb)
			indexb = indexb - indexa;
		else if (indexa == indexb)
			indexb = indexb - indexa;
	}
	else if (sizea/2 >= findpos(lst, i) && sizeb/2 <= findpos(lstb, current))
	{
		indexb += (sizeb - findpos(lstb, current));
		indexa += findpos(lst, i);
	}
	else if (sizea/2 <= findpos(lst, i) && sizeb/2 >= findpos(lstb, current))
	{
		indexa += (sizea - findpos(lst, i));
		indexb += findpos(lstb, current);
	}
	return (indexa + indexb);
}

int	whileit(t_list *lst, t_list *lstb)
{
	int		i;
	int		moves;
	int		lowest;
	int		needed;
	t_list	*temp;

	temp = lstb;
	needed = lstb->content;
	while (lstb)
	{
		i = supone(lst, lstb->content);
		if(lstb->content == temp->content && lstb)
		{
			lowest = calculate(lst, temp, lstb->content, i);
		}
		moves = calculate(lst, temp, lstb->content, i);
		if (moves < lowest && lstb)
		{
			needed = lstb->content;
		}
		lstb = lstb->next;
	}
	return (needed);
}

void	emptya(t_list **lst, t_list **lstb)
{
	while (ft_lstsize(*lst) > 3)
	{
		pushb(lst,lstb);
	}
}

/*


	1
	8
3	9
5	6
7	2
_	_
A	B

1ere etape
			Recuperer les prix

1 -> 3
8 -> 3
9 -> 3
6 -> 7
2 -> 3

ft_sup(list_a, int valeur->b);
ft_min(list_a);
ft_max(list_a);

2eme etape
			Calculer les prix et recuperer le total

si valeur va vers le haut : prix negatif
sinon: prix positif

si les 2 valeurs sont du meme signe: total = valeurmax(price_a, price_b)
sinon: total = abs(price_a) + abs(price_b);


			A	B		TOTAL
1 -> 3 =	0	0	=	0
8 -> 3 =	0	-1rb =	1 
9 -> 3 =	0	-2rb =	2
6 -> 7 =    1rra 2rrb =  2
2 -> 3 =	0	1rrb  = 1

3eme etape
			Executer les coups

while (lstb->size != 0)
{
	while (tempb)
	{
		comparer tous les totaux de chaque valeurs ds B
	}
}

*/