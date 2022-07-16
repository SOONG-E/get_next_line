/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:56:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/16 18:31:58 by yujelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

int	find_end(char *str, int len)
{
	int	idx;

	idx = 0;
	while (len--)
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (idx);
}

char	*strjoin(char const *s1, char const *s2)
{
	int		amount;
	char	*ret;
	int		idx1;
	int		idx2;

	if (!s2)
		return (NULL);
	amount = ft_strlen(s1) + ft_strlen(s2);
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

char	*split(char *str)
{
	unsigned char	*ret;
	int				loc;
	int				idx;
	int				idx2;

	loc = find_end(str, BUFFER_SIZE);
	ret = (char *)malloc(loc * sizeof(char));
	if (!ret)
		return (NULL);
	idx = -1;
	while (++idx < loc)
		ret[idx] = str[idx]
	return (ret);
}

char	*get_next_line(int fd)
{
	static unsigned char	*ret;
	unsigned char			*temp;

	temp = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!temp)
		return (NULL);
	read(fd, temp, BUFFER_SIZE);
	if (ft_strlen(temp) == 0)
		return (NULL);
	while (1)
	{
		ret = strjoin(ret, temp);
		if (find_end(temp, BUFFER_SIZE) < BUFFER_SIZE)
			break;
		read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	temp = 

}
