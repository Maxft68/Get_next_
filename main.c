/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:12:18 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/16 19:26:07 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	main(void)
{
	int fd;
    char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	printf("1ere fois 	        =>%s\n", line = get_next_line(fd));
	free(line);
	printf("2e fois 	        =>%s\n", line = get_next_line(fd));
	free(line);
	printf("3e fois 	        =>%s\n", line = get_next_line(fd));
	free(line);
	printf("4e fois			  %s\n", line = get_next_line(fd));
	free(line);
	printf("5e fois			  %s\n", line = get_next_line(fd));
	free(line);
	printf("6e fois			  %s\n", line = get_next_line(fd));
	free(line);
	printf("7e fois			  %s\n", line = get_next_line(fd));
	free(line);
	printf("8e fois			  %s\n", line = get_next_line(fd));
	free(line);
	printf("9e fois			  %s\n", line = get_next_line(fd));
	free(line);
	printf("10e fois 		  %s\n", get_next_line(fd));
    free(line);
    //printf("11e fois 		%s", get_next_line(fd));
	//printf("12e fois 		%s", get_next_line(fd)); 
	close(fd);
} */
#include <stdio.h>

int main(int argc, char **argv)
{
    char *line;
    int fd;

    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);

    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);

    }
    close(fd);
    return(0);
}