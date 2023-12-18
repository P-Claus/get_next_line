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

char	*put_buffer_in_stash(int fd, char *stash, char *buffer, char *temp)
{
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		printf("The buffer is: %s\n", buffer);
		if (stash != 0)
		{
			temp = ft_calloc(ft_strlen(stash), sizeof(char));
			if (!temp)
				return (NULL);
			temp = ft_strjoin(temp, stash);
			stash = malloc(sizeof(char) * ft_strlen(ft_strjoin(temp, buffer)));
			if (stash == NULL)
				return (NULL);
			stash = ft_strjoin(temp, buffer);
		}
		else if (stash == 0)
		{
			stash = ft_calloc(ft_strlen(buffer), sizeof(char));
			if (!stash)
				return (NULL);
			stash = ft_strjoin(stash, buffer);
		}
	}
	free(temp);
	return (stash);
}

char	*put_stash_in_line(char *stash, char *line, int count)
{
	line = ft_calloc(count, sizeof(char));
	if (line == NULL)
		return (NULL);
	while (stash[count] != '\n')
	{
		line[count] = stash[count];
		count++;
	}
	line[count] = '\n';
	return (line);
}

char	*remove_line_from_stash(char *stash, char *line)
{
//	char	*temp;
	int			new_stash_length;
	int			i;
	
	i = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	//printf("I is: %d\n", i);
	//temp = ft_calloc(ft_strlen(stash), sizeof(char));
	//if (!temp)
	//	return (NULL);
	new_stash_length = ft_strlen(stash) - ft_strlen(line);
	//printf("The length of new_stash is: %d\n", new_stash_length);
	ft_memmove((void *)stash, (void *)(stash + i), new_stash_length);
//	printf("Temp is: %s\n", temp);
	ft_bzero((stash + new_stash_length), ft_strlen(stash));
//	printf("The buffer in the rlfs function is: %s\n", buffer);
//	stash = ft_strjoin(stash, temp);
	return (stash);


}

char	*get_next_line(int fd)
{
	int			count;
	static char	*stash;
	char		*temp;
	char		*buffer;
	char		*line;

	if (fd == 0)
		return (NULL);
	if (!stash)
		stash = NULL;
	temp = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stash = put_buffer_in_stash(fd, stash, buffer, temp);
	line = NULL;
	count = 0;
	line = put_stash_in_line(stash, line, count);
	//printf("The line is: %s\n", line);
	//printf("The stash before rlfs is: %s\n", stash);
	remove_line_from_stash(stash, line);
	//printf("The stash after rlfs is: %s\n", stash);

	return (line);
}
