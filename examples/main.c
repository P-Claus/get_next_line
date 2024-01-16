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
	int	fd1;
	int	fd2;
	char	*line;

	fd1 = open("1char_no_nl.txt", O_RDONLY);
	fd2 = open("1char_mnl.txt", O_RDONLY);
	line = 	get_next_line(fd1);
	printf("The first line is: %s", line);
	free (line);


	line = 	get_next_line(fd2);
	printf("The second line is: %s", line);
	free (line);

	line = 	get_next_line(fd1);
	printf("The third line is: %s", line);
	free (line);

	line = 	get_next_line(fd2);
	printf("The fourth line is: %s", line);
	free (line);

	line = 	get_next_line(fd2);
	printf("The fifth line is: %s", line);
	free (line);
/*
	line = 	get_next_line(fd);
	printf("The sixth line is: %s", line);
	free (line);
*/

	close(fd1);
	close(fd2);
	return (0);
}
