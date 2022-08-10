/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:08:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/10 21:50:23 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#include <stdio.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
//#define BUFFER_SIZE 42  //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제no제하하기  제제발  제제바바제제바바

char	*ft_strjoin(char *str1, char *str2)
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

char	*read_temp(int fd, char *ret)
{
	int		idx;
	char	*temp;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	idx = 1;
	while (idx)
	{	
		idx = read(fd, temp, BUFFER_SIZE);
		if (idx == 0)
			break ;
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
	}
	free(temp);
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
		temp[idx++] = '\n';
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

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*box;
	char		*temp;

	if (BUFFER_SIZE < 1)
		return (NULL);
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
	if (ft_strlen(ret, 1) == 0)
	{
		free(ret);
		ret = NULL;
	}
	return (temp);
}

/*
//ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
int main()
{
	int fd = open("test4.txt", O_RDONLY);
	char c = 0;
	printf("%s", get_next_line(fd));
	read(fd, &c, 1);
	printf("%c \n", c);
}
*/



//bonus 수정 !!!!!!!!