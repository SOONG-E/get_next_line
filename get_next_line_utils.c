/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:49:19 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/10 21:11:32 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
	if (str[len] == '\n')
		len++;
	return (len);
}

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