/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:49:19 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/11 15:24:44 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_target_str(char *str, int target)
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
