/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2023/12/02 10:50:49 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			count;
	int			stash_index;
	char		*buffer;
	static char	stash[100];
	char		*line;

	buffer = ft_calloc(5 + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	stash_index = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, 5);
		count = 0;
		while (buffer[count] != '\0')
		{
			stash[stash_index++] = buffer[count];
			count++;
		}
	}
	stash[stash_index] = '\0';
	if (ft_strchr(stash, '\n'))
	{
		int	i = 0;
		while (stash[i++]!= '\n')
		{
			printf("I is: %d\n", i);
		}
		line = ft_calloc(i, sizeof(char));
		if (line == NULL)
			return (NULL);
		i = 0;
		while (stash[i] != '\n')
		{
			line[i] = stash[i];
			i++;
		}
		line[i] = '\n';
	}
		

	printf("The string in the buffer is: %s\n", buffer);
	printf("The string in the stash is: %s\n", stash);
	free(buffer);
	return (line);
}	
