/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:17 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/10 21:13:44 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

typedef struct s_fds
{
	int				fd;
	char			*box;
	struct s_fds	*next;
}	t_fds;

char	*get_next_line(int fd);
int		ft_target_str(char *str, int target);
int		ft_target_str(char *str, int target);
t_fds	*ft_lstnew(t_fds **lst, int fd);
t_fds	*ft_findfd(t_fds **lst, int target);
void	ft_deletefd(t_fds **lst, int fd);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);

#endif
