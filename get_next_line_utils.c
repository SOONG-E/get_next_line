/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:49:19 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/12 13:56:57 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str, int target)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != target)
			len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int	idx;

	idx = 0;
	while (str[idx] && str[idx] != c)
		idx++;
	if (str[idx] == c)
		return ((char *)&str[idx]);
	return (0);
}

char	*ft_free(char *ret, char *temp)
{
	if (temp)
		free(temp);
	free(ret);
	return (NULL);
}
