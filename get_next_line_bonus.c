/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:14 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/02 18:04:18 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#include <stdio.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
//#define BUFFER_SIZE 42  //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제no제하하기  제제발  제제바바제제바바

char	*strjoin(char *str1, char *str2)
{
	int		retidx;
	int		stridx;
	int		amount;
	char	*ret;

	amount = ft_strlen(str1, 1) + ft_strlen(str2, 1);
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

char	*read_temp(t_fds *lst, int fd, char *ret)
{
	int		idx;
	char	*temp;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	idx = read(fd, temp, BUFFER_SIZE);
	while (idx > 0)
	{
		temp[idx] = 0;
		ret = strjoin(ret, temp);
		if (!ret)
			return (NULL);
		if (ft_strlen(temp, 0) < idx)
			break ;
		idx = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	if (!ft_strlen(ret, 1) && idx <= 0)
	{
		ft_deletefd(&lst, fd);
		return (NULL);
	}
	return (ret);
}

char	*temp_split(char *ret)
{
	int		idx;
	char	*temp;

	temp = (char *)malloc((ft_strlen(ret, 0) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	idx = -1;
	while (ret[++idx] && ret[idx] != '\n')
		temp[idx] = ret[idx];
	if (ret[idx] == '\n')
	{
		temp[idx] = '\n';
		idx++;
	}
	temp[idx] = 0;
	return (temp);
}

char	*ret_tail(char *ret)
{
	char	*newret;
	int		idx;
	int		newidx;

	idx = ft_strlen(ret, 0);
	newret = (char *)malloc((ft_strlen(ret, 1) - idx + 1) * sizeof(char));
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

	temp = *lst;
	if (target < 0)
		return (NULL);
	if (!temp) //return (NULL)??
		return (ft_lstnew(lst, target));
	while (temp->next)
    {
    	if (temp->fd == target)
    		break ;
		temp = temp->next;
    }
	if (!temp->next)
		return (ft_lstnew(lst, target));
	return (temp);
}

void	ft_deletefd(t_fds **lst, int fd)
{
	t_fds	*temp;

	temp = *lst;
	if (temp->fd == fd)
	{
		if (temp->box)
		{
			free(temp->box);
			//temp->fd = ;
			temp = temp->next;
		}
		return ;
	}
	while (lst)
	{
		if (temp->next->fd == fd)
		{
			if (temp->next->box)
			{
				free(temp->next->box);
				//temp->next->fd = NULL;
				temp->next = temp->next->next;
			}
		}
		temp = temp->next;
	}
}

char	*get_next_line(int fd)
{
	static t_fds	*ret;
	t_fds	*r;
	char			*box;
	char		    *temp;

	r = ft_findfd(&ret, fd);
	if (!r)
		return (NULL);
	box = read_temp(ret, r->fd, r->box);
	if (!box)
		return (NULL);
	temp = temp_split(box);
	if (!temp)
		return (NULL);
	r->box = ret_tail(box);
	if (!r->box)
		return (NULL);
	return (temp);
}
/*
//ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
int main()
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("1- result1 -> %s", get_next_line(fd));
	
	printf("2- result2 -> %s", get_next_line(fd2));
	
	printf("1- result3 -> %s", get_next_line(fd));
	printf("2- result4 -> %s", get_next_line(fd2));
	
	printf("1- result5 -> %s", get_next_line(fd));
	printf("2- result6 -> %s", get_next_line(fd2));
	printf("1- result7 -> %s", get_next_line(fd));

}*/