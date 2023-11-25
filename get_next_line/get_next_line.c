/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/25 16:59:35 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			bytes_read;
	int			count;
	int			stash_index;
	char		*buffer;
	static char	stash[100];

	buffer = ft_calloc(5 + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	stash_index = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, 5);
		count = 0;
		while (buffer[count] != '\0')
		{
			stash[stash_index++] = buffer[count];
			count++;
	//	if (ft_strchr(stash, '\n'))
	//		break;
		}
	}
	
	stash[count] = '\0';

	printf("The amount of bytes that are read is: %d\n", bytes_read);
	printf("The string in the buffer is: %s\n", buffer);
	printf("The string in the stash is: %s\n", stash);

	return (stash);
}	
