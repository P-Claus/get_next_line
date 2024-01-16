/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:45:09 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/16 16:06:15 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;
	char	*line;

	fd = open("short_line_nl.txt", O_RDONLY);
	line = 	get_next_line(fd);
	printf("The first line is: %s", line);
	free (line);

	line = 	get_next_line(fd);
	printf("The second line is: %s", line);
	free (line);
/*
	line = 	get_next_line(fd);
	printf("The third line is: %s", line);
	free (line);

	line = 	get_next_line(fd);
	printf("The fourth line is: %s", line);
	free (line);

	line = 	get_next_line(fd);
	printf("The fifth line is: %s", line);
	free (line);

	line = 	get_next_line(fd);
	printf("The sixth line is: %s", line);
	free (line);
*/

	close(fd);
	return (0);
}
