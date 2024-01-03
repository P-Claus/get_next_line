/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:50:06 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/25 16:37:01 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#	define BUFFER_SIZE 5
# endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char    *ft_strchr(char *str, int c);
void    *ft_calloc(size_t num_elements, size_t element_size);
char  *ft_strjoin(char *dst, char *src); 

#endif
