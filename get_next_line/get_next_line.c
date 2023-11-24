/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/24 21:55:44 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(int fd)
{
	int		bytes_read;
	char	*buffer;
	static int	count = 1;

	printf("ft_calloc#[%d]---", count++);
	buffer = ft_calloc(5 + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, 5);
	if (bytes_read <= 0)
		return (free (buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*new_buffer;

	new_buffer = get_line(fd);
	return (new_buffer);	
}
