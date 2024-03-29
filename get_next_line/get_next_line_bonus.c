/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:16:34 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/11 10:16:55 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	string = ft_calloc((ft_strlen(stash) - count + 1), sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (stash[count])
		string[i++] = stash[count++];
	free (stash);
	return (string);
}

char	*put_stash_in_line(char *stash)
{
	int		count;
	char	*line;

	count = 0;
	if (!stash[count])
		return (NULL);
	line = ft_calloc((ft_strlen(stash) + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (stash[count] && stash[count] != '\n')
	{
		line[count] = stash[count];
		count++;
	}
	if (stash[count] == '\n')
		line[count] = stash[count];
	return (line);
}

char	*fill_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			free (stash);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
		free (buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = fill_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = put_stash_in_line(stash[fd]);
	stash[fd] = remove_line_from_stash(stash[fd]);
	if (stash[fd] && *stash[fd] == '\0')
	{
		free (stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
