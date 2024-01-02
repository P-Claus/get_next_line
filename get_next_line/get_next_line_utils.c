/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:41:47 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/25 16:35:39 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str++)
			return (0);
	}
	return ((char *)str);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;
	size_t	counter;
	size_t	total_size;

	counter = 0;
	total_size = num_elements * element_size;
	if (num_elements != 0 && element_size != 0 \
			&& total_size / num_elements != element_size)
		return (0);
	ptr = malloc(total_size);
	if (ptr == 0)
		return (0);
	while (counter < total_size)
	{
		((char *) ptr)[counter] = 0;
		counter++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	int		index;
	int		index_s1;
	int		index_s2;
	char	*new_string;

	index = 0;
	index_s1 = 0;
	index_s2 = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *) malloc((total_length + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (s1[index_s1] != '\0')
		new_string[index++] = s1[index_s1++];
	while (s2[index_s2] != '\0')
		new_string[index++] = s2[index_s2++];
	new_string[index++] = '\0';
	return (new_string);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;

	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		counter = len;
		while (counter > 0)
		{
			counter--;
			*(unsigned char *)(dst + counter) = \
				*(unsigned char *)(src + counter);
		}
	}
	else
	{
		counter = 0;
		while (counter < len)
		{
			*(unsigned char *)(dst + counter) = \
				*(unsigned char *)(src + counter);
			counter++;
		}
	}
	return (dst);
}
