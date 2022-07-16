/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:56:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/16 15:56:39 by yujelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	unsigned char *ret;

	ret = (char *)malloc(BUFFER_SIZE * sizeof(char));
	read(fd, ret, BUFFER_SIZE);

	
}
