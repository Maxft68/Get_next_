/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:12:18 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/01/03 19:43:31 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	main(void)
{
	int		fd;
	char	*line;
	char	*line;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	printf("1ere fois 		     =>%s\n", line = get_next_line(fd));
	free(line);
	printf("2e fois 		     =>%s\n", line = get_next_line(fd));
	free(line);
	printf("3e fois 		     =>%s\n", line = get_next_line(fd));
	free(line);
	printf("4e fois				%s\n", line = get_next_line(fd));
	free(line);
	printf("5e fois				%s\n", line = get_next_line(fd));
	free(line);
	printf("6e fois				%s\n", line = get_next_line(fd));
	free(line);
	printf("7e fois				%s\n", line = get_next_line(fd));
	free(line);
	printf("8e fois				%s\n", line = get_next_line(fd));
	free(line);
	printf("9e fois				%s\n", line = get_next_line(fd));
	free(line);
	printf("10e fois 			%s\n", get_next_line(fd));
	free(line);
	//printf("11e fois 		%s", get_next_line(fd));
	//printf("12e fois 		%s", get_next_line(fd));
	close(fd);
} */
#include <stdio.h>
/*
int	main(void)
{
	fd = open("empty.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 1;
	while (line && i < 50)
	{
		printf("%d> %s         ",i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("%s", line);
	close(fd);
	return(0);
}
*/
int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("empty.txt", O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("APPEL%d =%s", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}
