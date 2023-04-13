/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:40:50 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/14 00:37:43 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../Libft/libft.h"

void	printlst(t_list *lst);
void	printerror(t_list **lst, char **tab, char *str);
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
void	applymoves(t_list **lst, t_list **lstb, char *moves);

#endif