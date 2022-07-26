/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:08:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/26 21:59:07 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#include <stdio.h> //ㅈㅔ바ㄹ 제제출출하하기  전전에  삭삭제제하하기  제제발  제제바바제제바바
#define BUFFER_SIZE 1

int	ft_strlen(char *str, int flag)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	if (flag)
	{
		while (str[len])
			len++;
		return (len);
	}
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

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
		{
			ret[retidx++] = str1[stridx++];
			printf("\n\n\n%c??\n\n\n", ret[retidx-1]);
		}
		free(str1);
	}
	stridx = 0;
	while (str2[stridx])
	{
		ret[retidx++] = str2[stridx++];
		printf("\n\n\n\n%d\n\n\n", stridx);
		printf("\n\n\nlen = %d\n\n\n", ft_strlen(str2, 1));
		for(int i = 0; i<1000000000; i++);
	}
	ret[retidx] = 0;
	return (ret);
}

char	*read_temp(int fd, char *ret, char *temp)
{
	int	idx;
	int	tempidx;

	//printf("read_temp %s\n", ret);
	printf("\n\n\n\n\n%d\n\n\n\n\n\n", ft_strlen(ret, 1));
	idx = read(fd, temp, BUFFER_SIZE);
	if (!idx)
		return (ret);
	while (idx)
	{
		temp[idx] = 0;
		tempidx = 0;
		//printf("# -> %s\n", temp);
		while (temp[tempidx] && temp[tempidx] != '\n')
			tempidx++; 
		ret = strjoin(ret, temp);
		//printf("RET %s.\n", ret);
		//printf("@@%s\n", ret);
		if (!ret)
			return (NULL);
		//printf("SIZE!!! %d %d\n", tempidx, idx);
		if (tempidx < idx)
			break;
		idx = read(fd, temp, BUFFER_SIZE);
		printf("\n\n\nidx = %d\n\n\n", idx);
		
	}
	//printf("****%s****\n", ret);
	return (ret);
}
//ret 저장 temp 리턴
char	*temp_split(char *temp, char *ret)
{
	int	idx;

	free(temp);
	temp = (char *)malloc((ft_strlen(ret, 0) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	idx = 0;
	while (ret[idx] && ret[idx] != '\n')
	{
		temp[idx] = ret[idx];
		idx++;
	}
	if (ret[idx] == '\n')
	{
		temp[idx] = '\n';
		idx++;
	}
	temp[idx] = 0;
	return (temp);
}

char	*remain_ret(char *ret)
{
	char	*newret;
	int		idx;
	int		newidx;

	//printf("@@@ %d %d\n", ft_strlen(ret, 0), ft_strlen(ret, 1));
	idx = ft_strlen(ret, 0);
	newret = (char *)malloc((ft_strlen(ret, 1) - idx + 1) * sizeof(char));
	if (!newret)
		return (NULL);
	newidx = 0;
	while (ret[++idx])
		newret[newidx++] = ret[idx];
	newret[newidx] = 0;
	free(ret);
	//printf("newret %s\n", newret);
	return (newret);
}

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*temp;

	//printf("at the first time %s-\n", ret);
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp || fd < 0)
		return (NULL);
	ret = read_temp(fd, ret, temp);
	if (!ret)
		return (NULL);
	temp = temp_split(temp, ret);
	if (!temp)
		return (NULL);
	ret = remain_ret(ret);
	if (!ret)
		return (NULL);
	if (!ft_strlen(ret, 1))
		free(ret);
	return (temp);
}

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
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	printf("result6 -> %s", get_next_line(fd));
	//printf("result6 -> %s", get_next_line(fd));
}