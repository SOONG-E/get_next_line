/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:08:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/28 19:51:31 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#include <stdio.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#define BUFFER_SIZE 42  //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바

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

char	*read_temp(int fd, char *ret)
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
		free(ret);
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

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*temp;

	if (fd < 0)
		return (NULL);
	ret = read_temp(fd, ret);
	if (!ret)
		return (NULL);
	temp = temp_split(ret);
	if (!temp)
		return (NULL);
	ret = ret_tail(ret);
	if (!ret)
		return (NULL);
	return (temp);
}

/*
//ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
int main()
{
	int fd = open("test.txt", O_RDONLY);

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("result1 -> %s", get_next_line(fd));
	
	printf("result2 -> %s", get_next_line(fd));
	
	printf("result3 -> %s", get_next_line(fd));
	printf("result4 -> %s", get_next_line(fd));
	
	printf("result5 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));

}
*/