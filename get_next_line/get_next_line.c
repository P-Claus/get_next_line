/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2023/12/20 21:21:43 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*put_buffer_in_stash(int fd, char *buffer, char *stash, int	count)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	stash = ft_calloc((ft_strlen(buffer) + 1), sizeof(char));
	if (!stash)
		return (NULL);
//	while (buffer[count++] != '\0')
//		stash[count] = buffer[count];
	while (buffer[count] != '\0')
		printf("The char in buffer is: %c\n", buffer[count++]);
	printf("%d\n", bytes_read);
	return ("hello");
}

char	*put_stash_in_line(char *stash, char *line, int count)
{
	line = ft_calloc((ft_strlen(stash)), sizeof(char));
	if (!line)
		return (NULL);
	while (stash[count] && stash[count] != '\n')
	{
		line[count] = stash[count];
		count++;
	}
	line[count] = '\n';
	return (line);
}

char	*remove_line_from_stash(char *stash, char *line)
{
	int			new_stash_length;
	int			i;
	
	i = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	new_stash_length = ft_strlen(stash) - ft_strlen(line);
	ft_memmove((void *)stash, (void *)(stash + i), new_stash_length);
	ft_bzero((stash + new_stash_length), ft_strlen(stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	//char		*line;

	if (fd == 0)
		return (NULL);
	if (!stash)
		stash = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stash = put_buffer_in_stash(fd, buffer, stash, 0);
	if (!stash)
	{
		free (buffer);
		free (stash);
		return (NULL);
	}
	/*line = 0;
	line = put_stash_in_line(stash, line, 0);
	remove_line_from_stash(stash, line);
	free(buffer);
	return (line);*/
	return (stash);
}
