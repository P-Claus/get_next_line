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

void	copy_string(char *s1, char *s2, int count)
{
	while (s2[count])
	{
		s1[count] = s2[count];
		count++;
	}
}

char	*put_buffer_in_stash(int fd, char *stash, char *buffer)
{
	int	bytes_read;
	char	*temp;

	while ((!ft_strchr(buffer, '\n')) && BUFFER_SIZE >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			return (NULL);
		if (stash == NULL)
		{
			stash = ft_calloc(ft_strlen(buffer), sizeof(char));
			copy_string(stash, buffer, 0);
		}
		else if (stash != NULL)
		{
			temp = ft_calloc(ft_strlen(stash), sizeof(char));
			copy_string(temp, stash, 0);
			free(stash);
			stash = ft_strjoin(temp, buffer);
			free(temp);
		}
	}
	return (stash);
}

char	*put_stash_in_line(char *stash, char *line)
{
	int	count;

	count = 0;
	line = ft_calloc((ft_strlen(stash)), sizeof(char));
	if (!line)
		return (NULL);
	while (stash[count] != '\n')
	{
		line[count] = stash[count];
		count++;
	}
	line[count] = '\n';
	return (line);
}

void	remove_line_from_stash(char *stash, size_t length_of_line)
{
	int			new_stash_length;
	int			i;
	
	i = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	printf("the char is %c\n", stash[i]);
	printf("The length of stash is: %lu\n", ft_strlen(stash));
	printf("The length of line is: %lu\n", length_of_line);
	new_stash_length = ft_strlen(stash) - length_of_line;
	printf("The new_stash_length is: %d\n", new_stash_length);
	//working on this function -> the line and everything is working
	//but still need to figure out how to make sure 
	ft_memmove((void *)stash, (void *)(stash + i), new_stash_length);
	ft_bzero((stash + new_stash_length), ft_strlen(stash));
	printf("The stash is: %s\n", stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd <= 0)
		return (NULL);
	if (!stash)
		stash = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stash = put_buffer_in_stash(fd, stash, buffer);
	if (!stash)
	{
		free (buffer);
		free (stash);
		return (NULL);
	}
	line = 0;
	line = put_stash_in_line(stash, line);
	printf("1: The line is: %s\n", line);
	remove_line_from_stash(stash, ft_strlen(line));
	printf("2: The line is: %s\n", line);
	free(buffer);
	return (line);
}
