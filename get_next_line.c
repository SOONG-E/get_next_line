/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:56:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/16 18:41:03 by yujelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 42

int	find_nl(char *str, int len)
{
	int	idx;

	idx = 0;
	while (len--)
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*strjoin(char *s1, char *s2, unsigned int s1size, unsigned int s2size)
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
	while (s1[idx1])
		ret[idx2++] = s1[idx1++];
	idx1 = 0;
	while (s2[idx1])
		ret[idx2++] = s2[idx1++];
	ret[idx2] = 0;
	return (ret);
}

char	*split(char *temp, char *str, unsigned int strsize)
{
	char	*ret;
	int				loc;
	int				idx;

	free(temp);
	loc = find_nl(str, strsize);
	ret = (char *)malloc((loc + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	idx = -1;
	while (++idx < loc)
		ret[idx] = str[idx];
	ret[idx] = 0;
	return (ret);
}

char	*makenewstr(char *str, unsigned int strsize)
{
	char	*ret;
	unsigned int	loc;
	int	idx;

	loc = find_nl(str, strsize);
	ret = (char *)malloc((strsize - loc) * sizeof(char));
	if (!ret)
		return (NULL);
	idx = -1;
	while (loc < strsize)
		ret[++idx] = str[++loc];
	return (ret);
}

void freeall()
{

}

char	*get_next_line(int fd)
{
	static char			*ret;
	char				*temp;
	static unsigned int	retsize;
	unsigned int		tempsize;

	temp = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!temp)
		return (NULL);
	tempsize = read(fd, temp, BUFFER_SIZE);
	if (tempsize == 0)
			return (NULL);
	retsize = 0;
	while (tempsize)
	{
		ret = strjoin(ret, temp, retsize, tempsize);
		retsize += tempsize;
		if (find_nl(temp, tempsize) < BUFFER_SIZE)
			break;
		tempsize = read(fd, temp, BUFFER_SIZE);
	}
	temp = split(temp, ret, retsize);
	if (!temp)
		return (NULL);
	ret = makenewstr(ret, retsize);
	if (!ret)
		return (NULL);
	retsize -= find_nl(ret, retsize);
	return (temp);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);

	get_next_line(fd);
}