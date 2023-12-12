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

char    *put_buffer_in_stash(int fd, char *stash)
{
    char    *buffer;
    char    *temp;

    if (!(buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
        return (NULL);
    temp = NULL;
    while (!ft_strchr(buffer, '\n'))
    {
        read(fd, buffer, BUFFER_SIZE);
        if (stash != 0)
        {
            if (!(temp = ft_calloc((ft_strlen(stash)), sizeof(char))))
                return(NULL);
            temp = ft_strjoin(temp, stash);
            stash = malloc(sizeof(char) * ft_strlen(ft_strjoin(temp, buffer)));
            if (stash == NULL)
                return (NULL);
            stash = ft_strjoin(temp, buffer);
            }
        else if (stash == 0)
        {
            if (!(stash = malloc(sizeof(char) * ft_strlen(buffer))))
                return (NULL);
            stash = ft_strjoin(stash ,buffer);
        }
    }
    return (stash);
    }


char	*get_next_line(int fd)
{
    static  char    *stash;

    stash = NULL;
    stash = put_buffer_in_stash(fd, stash);
    return (stash);
}
