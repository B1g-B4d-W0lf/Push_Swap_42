/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:04:16 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/14 00:40:21 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct g_list
{
	char			*content;
	struct g_list	*next;
}					t_lst;

t_lst	*ft_lstnewnew(char *content, t_lst *lst, int boolean);
char	*ft_lstaddback(t_lst **lst, t_lst *new, char *west, int boolean);
int		ft_strlenfree(char *str, t_lst *tab, int boolean);
int		ft_lstiternew(t_lst *lst, int (*f)(char *, t_lst *tab, int boolean));
char	*fillstr(t_lst *tab, int index);
char	*get_next_line(int fd);
int		checkbuffer(char c, char const *set);
char	*readit(int fd, char *west, t_lst **tab);
int		writetemp(char *temp, char *str, int boolean);
char	*westigation(char *west, char *buffer, t_lst **tab, int boolean);

#endif