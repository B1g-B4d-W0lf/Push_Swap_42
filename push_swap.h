/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:50 by wfreulon          #+#    #+#             */
/*   Updated: 2023/03/30 23:08:41 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

void	printlst(t_list *lst);
void	printerror(void);
void	clearlst(t_list **lst);
int		main(int argc, char **argv);

//parse
void	checkdigits(char *argv, char *k, int bin);
int		checkargv(int argc, char **argv, int i);
t_list	*string(char *arg);
t_list	*array(int argc, char **argv);
t_list	*sora(int argc, char **argv);

//moves
void	swapa(t_list **lst);
void	pusha(t_list **lsta, t_list **lstb);
void	rotatea(t_list **lst);
void	reversera(t_list **lst);
void	swapb(t_list **lst);
void	pushb(t_list **lsta, t_list **lstb);
void	rotateb(t_list **lst);
void	reverserb(t_list **lst);
void	douleswap(t_list **lsta, t_list **lstb);
void	doublerotate(t_list **lsta, t_list **lstb);
void	doublereverser(t_list **lsta, t_list **lstb);

//diff
int		findmax(t_list *lst);
int		findmin(t_list *lst);
int		diffint(t_list *lst, int i);
int		compare(int i, int j);

//algo
void	sort(t_list **lst, t_list **lstb);
void	cheapest(t_list **lst, t_list **lstb);
void	finalmove(t_list **lst, t_list **lstb);
void	moveit(t_list **lst, t_list **lstb, int i, int j);


#endif