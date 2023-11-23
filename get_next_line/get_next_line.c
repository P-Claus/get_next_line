/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/23 22:05:56 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc(5 + 1, sizeof(char));
	bytes_read = read(fd, buffer, 5);

	printf("The amount of bytes read is: %d\n", bytes_read);
	printf("The string is: %s\n", buffer);

	buffer = ft_calloc(5 + 1, sizeof(char));
	bytes_read = read(fd, buffer, 5);

	printf("The amount of bytes read is: %d\n", bytes_read);
	printf("The string is: %s\n", buffer);

	/*
	while ((bytesRead = read(fd, buffer, 10)))
	{
		if (!ft_strchr(buffer, '\n'))
		{
			printf("The char is: %s\n", buffer);
			printf("The byte is: %d\n", bytesRead);
		}
	}*/
	return (buffer);
}
