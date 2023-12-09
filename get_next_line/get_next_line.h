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

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char    *ft_strchr(const char *str, int c);
void    *ft_calloc(size_t num_elements, size_t element_size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char  *ft_strjoin(char const *s1, char  const *s2); 
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
