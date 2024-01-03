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

char	*remove_line_from_stash(char *stash)
{
	int		count;
	int		i;
	char	*string;

	count = 0;
	while (stash[count] && stash[count] != '\n')
		count++;
	if (!stash[count])
	{
		free (stash);
		return (NULL);
	}
	count++;
	string = ft_calloc((ft_strlen(stash) - count), sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (stash[count])
		string[i++] = stash[count++];
	free (stash);
	return (string);
}

char	*put_stash_in_line(char *stash, char *line)
{
	int	count;

	count = 0;
	
	while (stash[count] && stash[count] != '\n')
	{
		line[count] = stash[count];
		count++;
	}
	return (line);
}

char	*fill_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	line = ft_calloc((ft_strlen(stash) + 1), sizeof(char));
	if (!line)
		return (NULL);
	line = put_stash_in_line(stash, line);
	stash = remove_line_from_stash(stash);

	return (line);
}
