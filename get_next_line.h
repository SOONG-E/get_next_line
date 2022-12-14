/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:20:40 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/12 13:56:46 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
int		ft_strlen(char *str, int target);
char	*temp_split(char *ret);
char	*ft_strchr(const char *str, int c);
char	*ft_free(char *ret, char *temp);

#endif
