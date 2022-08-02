/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:17 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/02 17:59:33 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

typedef struct s_fds
{
    int     fd;
    char    *box;
    struct s_fds   *next;
}   t_fds;

char	*get_next_line(int fd);
int		ft_strlen(char *str, int flag);
void	ft_deletefd(t_fds **lst, int fd);

#endif