/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 18:22:00 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/13 18:22:09 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int fd;
	int gnl;

	gnl = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	gnl = get_next_line(fd, &line);
	while (gnl != 0 && gnl != -1)
	{
		printf("%s\n", line);
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
		printf("Error reading file.\n");
	if (fd != 0)
		close (fd);
	return (0);
}
