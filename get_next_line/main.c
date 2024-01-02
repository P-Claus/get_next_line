/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:45:09 by pclaus            #+#    #+#             */
/*   Updated: 2023/12/20 19:32:32 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;
	char	*next_line;

	fd = open("example11.txt", O_RDONLY);
	next_line = get_next_line(fd);

	printf("The first line in fd is: %s\n", next_line);
	free(next_line);

	next_line = get_next_line(fd);
	printf("The second line in fd is: %s\n", next_line);
	free(next_line);
	
	next_line = get_next_line(fd);
	printf("The third line in fd is: %s\n", next_line);
	free(next_line);

	next_line = get_next_line(fd);
	printf("The fourth line in fd is: %s\n", next_line);
	free(next_line);

	next_line = get_next_line(fd);
	printf("The fifth line in fd is: %s\n", next_line);
	free(next_line);

	next_line = get_next_line(fd);
	printf("The sixth line in fd is: %s\n", next_line);
	free(next_line);



	close(fd);
	return (0);
	/*

	printf("test1");
	int    fd;
	char  *next_line;
	fd = open("example2.txt", O_RDONLY);
	if (fd == -1)
		printf("There was an error opening the file");

	printf("test before put buffer in stash");
	next_line = get_next_line(fd);
	printf("The first line in fd is: %s\n", next_line);


	close(fd);
	free(next_line);
	return (0);
	*/
}
