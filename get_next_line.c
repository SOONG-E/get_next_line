/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:08:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/11 15:24:15 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin(char *str1, char *str2)
{
	int		retidx;
	int		stridx;
	int		amount;
	char	*ret;

	amount = ft_target_str(str1, 0) + ft_target_str(str2, 0);
	ret = (char *)malloc((amount + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	retidx = 0;
	if (str1)
	{
		stridx = 0;
		while (str1[stridx])
			ret[retidx++] = str1[stridx++];
		free(str1);
	}
	stridx = 0;
	while (str2[stridx])
		ret[retidx++] = str2[stridx++];
	ret[retidx] = 0;
	return (ret);
}

char	*read_temp(int fd, char *ret)
{
	int		idx;
	char	*temp;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	idx = read(fd, temp, BUFFER_SIZE);
	while (idx)
	{	
		if (idx == -1)
		{
			free(ret);
			break ;
		}
		temp[idx] = 0;
		ret = ft_strjoin(ret, temp);
		if (!ret)
			return (NULL);
		if (ft_strchr(ret, '\n'))
			break ;
		idx = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	return (ret);
}

char	*temp_split(char *ret)
{
	int		idx;
	char	*temp;

	temp = (char *)malloc((ft_target_str(ret, '\n') + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	idx = -1;
	while (ret[++idx] && ret[idx] != '\n')
		temp[idx] = ret[idx];
	if (ret[idx] == '\n')
		temp[idx++] = '\n';
	temp[idx] = 0;
	return (temp);
}

char	*ret_tail(char *ret)
{
	char	*newret;
	int		idx;
	int		newidx;

	idx = ft_target_str(ret, '\n');
	newret = (char *)malloc((ft_target_str(ret, 0) - idx + 1) * sizeof(char));
	if (!newret)
		return (NULL);
	newidx = 0;
	while (ret[idx])
		newret[newidx++] = ret[idx++];
	newret[newidx] = 0;
	if (ret)
		free(ret);
	return (newret);
}

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*box;
	char		*temp;

	box = read_temp(fd, ret);
	if (!box)
	{
		ret = NULL;
		return (NULL);
	}
	temp = temp_split(box);
	if (!temp)
		return (NULL);
	ret = ret_tail(box);
	if (!ret)
		return (NULL);
	if (ft_target_str(ret, 0) == 0)
	{
		free(ret);
		ret = NULL;
	}
	return (temp);
}
