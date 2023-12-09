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
	static  char  *stash;
  char		      *buffer;
  char          *temp;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
  temp = NULL;
	if (buffer == NULL)
		return (NULL);
  while (!ft_strchr(buffer, '\n'))
  {
    read(fd, buffer, BUFFER_SIZE);
    if (stash != 0)
    {
      printf("Temp in test 1 before ft_calloc is: %s\n", temp);
      temp = ft_calloc((ft_strlen(stash)), sizeof(char));
      printf("Temp in test 1 after ft_calloc is: %s\n", temp);
      ft_strlcpy(temp, stash, ft_strlen(stash) + 1 );
      printf("Temp after ft_strlcpy is: %s\n", temp),
      printf("The stash in test 1 before malloc is: %s\n", stash);
      stash = malloc(sizeof(char) * ft_strlen(ft_strjoin(stash, buffer)));
      printf("The stash in test 1 after malloc is: %s\n", stash);
      if (stash == NULL)
          return (NULL);

      stash = ft_strjoin(temp, buffer);
      printf("The stash in test 1 at the end is: %s\n", stash);
    }
    else if (stash == 0)
    {
      //printf("Temp is: %s\n", temp);
      //printf("Test 2\n");
      //printf("The stash in test 2 before malloc is: %s\n", stash);
      stash = malloc(sizeof(char) * ft_strlen(buffer));
      //printf("The stash in test 2 after malloc is: %s\n", stash);
      if (stash == NULL)
        return (NULL);
      stash = ft_strjoin(stash ,buffer);
      //printf("The stash in test 2 at the end is: %s\n", stash);
    }
    
    printf("Test 3\n");
  }
	printf("The string in the buffer is: %s\n", buffer);
  printf("The stash is: %s\n", stash);
  return (stash);
}	
