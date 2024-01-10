/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:45:09 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/04 15:28:40 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
/*	int	fd;
	char	*line;

	fd = open("example7.txt", O_RDONLY);
	line = 	get_next_line(fd);
	printf("The first line is: %s", line);
	free (line);
	
	line = 	get_next_line(fd);
	printf("The second line is: %s", line);
	free (line);

	close(fd);
	return (0);
	*/

	int fd;
	char *line;

	fd = open("example.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("The line is: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("The line is: %s", line);
	free(line);

	close(fd);
	return (0);
}
