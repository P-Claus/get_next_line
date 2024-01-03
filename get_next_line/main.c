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
	char	*line;

	fd = open("example10.txt", O_RDONLY);
	line = 	get_next_line(fd);
	printf("The first line is: %s", line);
	free (line);
	
	//line = 	get_next_line(fd);
	//printf("The second line is: %s", line);
	//free (line);
	//printf("Test");

	close(fd);
	return (0);
}
