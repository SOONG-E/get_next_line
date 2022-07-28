/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:49:19 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/28 19:52:25 by yujelee          ###   ########seoul.kr  */
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
