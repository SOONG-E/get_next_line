/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:19 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/11 19:46:25 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

int	ft_strlen(char *str, int endchr)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != endchr)
			len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		retidx;
	int		stridx;
	int		amount;
	char	*ret;

	amount = ft_strlen(str1, 0) + ft_strlen(str2, 0);
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

t_fds	*ft_lstnew(t_fds **lst, int fd)
{
	t_fds	*ret;

	ret = (t_fds *)malloc(sizeof(t_fds));
	if (!ret)
		return (NULL);
	ret->fd = fd;
	ret->box = NULL;
	ret->next = *lst;
	*lst = ret;
	return (ret);
}

t_fds	*ft_findfd(t_fds **lst, int target)
{
	t_fds	*temp;

	if (target < 0)
		return (NULL);
	temp = *lst;
	if (!temp)
		return (ft_lstnew(lst, target));
	while (temp)
	{
		if (temp->fd == target)
			break ;
		temp = temp->next;
	}
	if (!temp)
		return (ft_lstnew(lst, target));
	return (temp);
}

void	ft_deletefd(t_fds **lst, int fd)
{
	t_fds	*target;
	t_fds	*temp;

	temp = *lst;
	if (temp->fd == fd)
	{
		target = temp;
		*lst = temp->next;
		free(target);
	}
	else
	{
		while (temp->next)
		{
			if (temp->next->fd == fd)
			{
				target = temp->next;
				temp->next = temp->next->next;
				free(target);
				break ;
			}
			temp = temp->next;
		}
	}
}
