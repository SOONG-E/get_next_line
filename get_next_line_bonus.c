/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:14 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/10 21:13:20 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#include <stdio.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
// #define BUFFER_SIZE 42  //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제no제하하기  제제발  제제바바제제바바

char	*read_temp(t_fds **lst, int fd, char *ret)
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
		ret = ft_strjoin(ret, temp);
		if (!ret)
			return (NULL);
		if (ft_target_str(temp, '\n') < idx)
			break ;
		idx = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	if (!ft_target_str(ret, 0) && idx <= 0)
	{
		free(ret);
		ft_deletefd(lst, fd);
		return (NULL);
	}
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

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if ((char) c == '\0')
		return ((char *) str);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fds	*lst;
	t_fds			*fbox;
	char			*box;
	char			*temp;

	fbox = ft_findfd(&lst, fd);
	if (!fbox)
		return (NULL);
	box = read_temp(&lst, fbox->fd, fbox->box);
	if (!box)
		return (NULL);
	temp = temp_split(box);
	fbox->box = ret_tail(box);
	if (!fbox->box)
		return (NULL);
	if (ft_target_str(fbox->box, 0) == 0)
	{
		free(fbox->box);
		fbox->box = NULL;
		ft_deletefd(&lst, fd);
	}
	return (temp);
}

/*
//ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
int main()
{
	int fd = open("test4.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("-> %s", get_next_line(fd));
	printf("-> %s", get_next_line(fd));
	printf("-> %s", get_next_line(fd));
	printf("-> %s", get_next_line(fd));

}*/