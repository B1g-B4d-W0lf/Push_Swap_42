/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:50 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 04:03:42 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

void	printlst(t_list *lst);
void	printerror(t_list **lst, char **tab, char *str, t_list **lstb);
void	clearlst(t_list **lst);
int		main(int argc, char **argv);

//parse
int		checkdigits(char *argv, char *k, int bin);
int		checkargv(int argc, char **argv, int i);
void	finalcheck(t_list *lst);
t_list	*string(int argc, char **argv);
void	freetab(char **tab);

//moves
void	swapa(t_list **lst);
void	pusha(t_list **lsta, t_list **lstb);
void	rotatea(t_list **lst);
void	reversera(t_list **lst);
void	swapb(t_list **lst);
void	pushb(t_list **lsta, t_list **lstb);
void	rotateb(t_list **lst);
void	reverserb(t_list **lst);
void	doubleswap(t_list **lsta, t_list **lstb);
void	doublerotate(t_list **lsta, t_list **lstb);
void	doublereverser(t_list **lsta, t_list **lstb);
void	triplereverse(t_list **lst);

//diff
int		findmax(t_list *lst);
int		findmin(t_list *lst);
int		diffint(t_list *lst, int i);
int		compare(int i, int j);
int		supone(t_list *lst, int i);

//algo
void	sort(t_list **lst, t_list **lstb);
void	cheapest(t_list **lst, t_list **lstb);
void	finalmove(t_list **lst, t_list **lstb, int i, int j);
void	moveit(t_list **lst, t_list **lstb, int i, int j);
void	emptya(t_list **lst, t_list **lstb);
int		whileit(t_list *lst, t_list *lstb);
int		findpos(t_list *lst, int i);
void	efficient(t_list **lst, t_list **lstb, int moving);

//operations&calculs
void	bothinf(t_list **lst, t_list **lstb, int moving, int sup);
void	bothsup(t_list **lst, t_list **lstb, int moving, int sup);
void	infsup(t_list **lst, t_list **lstb, int moving, int sup);
void	supinf(t_list **lst, t_list **lstb, int moving, int sup);
int		firstop(t_list *lst, t_list *lstb, int current, int sup);
int		secondop(t_list *lst, t_list *lstb, int current, int sup);
int		thirdop(t_list *lst, t_list *lstb, int current, int sup);
int		fourthop(t_list *lst, t_list *lstb, int current, int sup);

#endif