/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:45:09 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/26 18:27:26 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int    fd;
	//int    fd2;
	char  *next_line;
	//char	*next_line2;
	fd = open("example5.txt", O_RDONLY);
	//fd2 = open("example2.txt", O_RDONLY);

	next_line = get_next_line(fd);
	printf("The first line in fd is: %s\n", next_line);

	next_line = get_next_line(fd);
	printf("The second line in fd is: %s\n", next_line);

	//next_line2 = get_next_line(fd2);
	//printf("The first line in fd2 is: %s\n", next_line2);

	next_line = get_next_line(fd);
	printf("The third line in fd is: %s\n", next_line);

	next_line = get_next_line(fd);
	printf("The fourth line in fd is: %s\n", next_line);

	next_line = get_next_line(fd);
	printf("The fifth line in fd is: %s\n", next_line);

	close(fd);
	//close(fd2);
	if (next_line)
		free(next_line);
	return (0);
}
