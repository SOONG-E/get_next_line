/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:56:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/18 21:54:33 by yujelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 42

int	find_nl(char *str, int len)
{
	int	idx;

	idx = 0;
	while (len--)
	{
		if (str[idx] == '\n'|| str[idx] == 0)
			return (idx);
		idx++;
	}
	return (idx);
}

char	*strjoin(char *s1, char *s2, int s1size, int s2size)
{
	int		amount;
	char	*ret;
	int		idx1;
	int		idx2;

	if (!s2)
		return (NULL);
	amount = s1size + s2size;
	ret = (char *)malloc((amount + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	idx1 = 0;
	idx2 = 0;
	while (idx1 < s1size)
		ret[idx2++] = s1[idx1++];
	idx1 = 0;
	while (idx1 < s2size)
		ret[idx2++] = s2[idx1++];
	free(s1);
	return (ret);
}

char	*split(char *temp, char *str, int strsize)
{
	char	*ret;
	int		loc;
	int		idx;

	free(temp);
	loc = find_nl(str, strsize);
	ret = (char *)malloc((loc + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	idx = -1;
	while (++idx < loc)
		ret[idx] = str[idx];
	ret[++idx] = 0;
	return (ret);
}

char	*makenewstr(char *str, int *strsize)
{
	char	*ret;
	int		loc;
	int		temp;
	int		idx;

	loc = find_nl(str, *strsize);
	temp = *strsize - loc - 1;
	ret = (char *)malloc((*strsize - loc) * sizeof(char));
	if (!ret)
		return (NULL);
	idx = -1;
	while (loc < *strsize)
		ret[++idx] = str[++loc];
	*strsize = temp;
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*temp;
	static int	retsize;
	int			tempsize;

	if (fd < 0)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!temp)
		return (NULL);
  	tempsize = read(fd, temp, BUFFER_SIZE);
	if (tempsize == 0 && retsize <= 0)
	{
		free(temp);
		return (NULL);
	}
	while (tempsize || retsize)
	{
		ret = strjoin(ret, temp, retsize, tempsize);
		if (!ret)
			return (NULL);
		retsize += tempsize;
		if (find_nl(ret, retsize) < retsize || !tempsize)
			break ;
		tempsize = read(fd, temp, BUFFER_SIZE);
	}
	temp = split(temp, ret, retsize);
	if (!temp)
		return (NULL);
	ret = makenewstr(ret, &retsize);
	if (!ret)
		return (NULL);
	//if (retsize <= 0&& !tempsize && ret)
	//	free(ret);
	//printf("#END %d\n#%s\n", retsize, ret);
	return (temp);
}


int main()
{
	int fd = open("test.txt", O_RDONLY);

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("result1 -> %s \n", get_next_line(fd));
	
	printf("result2 -> %s \n", get_next_line(fd));
	
	printf("result3 -> %s \n", get_next_line(fd));
	printf("result4 -> %s \n", get_next_line(fd));
	printf("result5 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	printf("result6 -> %s \n", get_next_line(fd));
	//printf("result6 -> %s \n", get_next_line(fd));
	
}