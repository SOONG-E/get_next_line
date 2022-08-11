/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:14 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/11 20:23:57 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	int	idx;

	idx = 0;
	while (str[idx] && str[idx] != c)
		idx++;
	if (str[idx] == c)
		return ((char *)&str[idx]);
	return (0);
}

char	*read_temp(t_fds **lst, int fd, char *ret)
{
	int		idx;
	char	*temp;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (ft_free(lst, fd, ret, temp));
	idx = read(fd, temp, BUFFER_SIZE);
	while (idx > 0)
	{
		temp[idx] = 0;
		ret = ft_strjoin(ret, temp);
		if (!ret)
			return (ft_free(lst, fd, ret, temp));
		if (ft_strchr(temp, '\n'))
			break ;
		idx = read(fd, temp, BUFFER_SIZE);
	}
	if ((!ft_strlen(ret, 0) && idx == 0) || idx < 0)
		return (ft_free(lst, fd, ret, temp));
	free(temp);
	return (ret);
}

char	*ft_free(t_fds **lst, int fd, char *ret, char *temp)
{
	if (temp)
		free(temp);
	free(ret);
	ret = NULL;
	ft_deletefd(lst, fd);
	return (NULL);
}

char	*temp_split(t_fds **lst, int fd, char **ret)
{
	int		idx;
	int		newidx;
	char	*temp;
	char	*newret;

	temp = (char *)malloc((ft_strlen(*ret, '\n') + 1) * sizeof(char));
	if (!temp)
		return (ft_free(lst, fd, *ret, temp));
	idx = -1;
	while ((*ret)[++idx] && (*ret)[idx] != '\n')
		temp[idx] = (*ret)[idx];
	if ((*ret)[idx] == '\n')
		temp[idx++] = '\n';
	temp[idx] = 0;
	newret = (char *)malloc((ft_strlen(*ret, 0) - \
	ft_strlen(*ret, '\n') + 1) * sizeof(char));
	if (!newret)
		return (ft_free(lst, fd, *ret, temp));
	newidx = 0;
	while ((*ret)[idx])
		newret[newidx++] = (*ret)[idx++];
	newret[newidx] = 0;
	free(*ret);
	*ret = newret;
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_fds	*lst;
	t_fds			*fbox;
	char			*temp;
	char			*box;

	fbox = ft_findfd(&lst, fd);
	if (!fbox)
		return (NULL);
	box = read_temp(&lst, fbox->fd, fbox->box);
	if (!box)
		return (NULL);
	fbox->box = box;
	temp = temp_split(&lst, fd, &fbox->box);
	if (!temp)
		return (NULL);
	if (ft_strlen(fbox->box, 0) == 0)
	{
		free(fbox->box);
		fbox->box = NULL;
		ft_deletefd(&lst, fd);
	}
	return (temp);
}
