/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:45:09 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/23 21:55:06 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	//char 	*read_str;

	fd = open("example.txt", O_RDONLY);

	get_next_line(fd);


	return (0);
}
