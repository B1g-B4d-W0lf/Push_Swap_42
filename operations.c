/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:43:41 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/11 02:05:55 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	firstop(t_list *lst, t_list *lstb, int current, int sup)
{
	int	indexa;
	int	indexb;

	indexa = 0;
	indexb = 0;
	indexb += findpos(lstb, current);
	indexa += findpos(lst, sup);
	if (indexa > indexb)
		indexa = indexa - indexb;
	else if (indexa < indexb)
		indexb = indexb - indexa;
	else if (indexa == indexb)
		indexb = indexb - indexa;
	return (indexa + indexb);
}

int	secondop(t_list *lst, t_list *lstb, int current, int sup)
{
	int	indexa;
	int	indexb;
	int	sizea;
	int	sizeb;

	sizea = ft_lstsize(lst);
	sizeb = ft_lstsize(lstb);
	indexa = 0;
	indexb = 0;
	indexb += (sizeb - findpos(lstb, current));
	indexa += (sizea - findpos(lst, sup));
	if (indexa > indexb)
		indexa = indexa - indexb;
	else if (indexa < indexb)
		indexb = indexb - indexa;
	else if (indexa == indexb)
		indexb = indexb - indexa;
	return (indexa + indexb);
}

int	thirdop(t_list *lst, t_list *lstb, int current, int sup)
{
	int	indexa;
	int	indexb;
	int	sizeb;

	sizeb = ft_lstsize(lstb);
	indexa = 0;
	indexb = 0;
	indexb += (sizeb - findpos(lstb, current));
	indexa += findpos(lst, sup);
	return (indexa + indexb);
}

int	fourthop(t_list *lst, t_list *lstb, int current, int sup)
{
	int	indexa;
	int	indexb;
	int	sizea;

	sizea = ft_lstsize(lst);
	indexa = 0;
	indexb = 0;
	indexa += (sizea - findpos(lst, sup));
	indexb += findpos(lstb, current);
	return (indexa + indexb);
}
