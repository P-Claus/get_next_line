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

char *store_buffer_in_stash(char *buffer)
{
  static char *stash;
  if (stash == 0)
  {
    stash = malloc(sizeof(char) * ft_strlen(buffer));
      if (stash == NULL)
        return (NULL);
      stash = ft_strjoin(stash ,buffer);
  }
  else
  {
    stash = malloc(sizeof(char) * ft_strlen(ft_strjoin(stash, buffer)));
    if (stash == NULL)
        return (NULL);
    stash = ft_strjoin(stash, buffer);
  }
  printf("The stash is: %s\n", stash);
  return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
  int   bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
  bytes_read = read(fd, buffer, BUFFER_SIZE);
  store_buffer_in_stash(buffer);
  bytes_read = read(fd, buffer, BUFFER_SIZE);
  store_buffer_in_stash(buffer);

	printf("The string in the buffer is: %s\n", buffer);
  printf("The bytes read is: %d\n", bytes_read);
  return (buffer);
}	
