/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:41:47 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/23 22:02:25 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
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
