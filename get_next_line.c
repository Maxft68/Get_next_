/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:58:15 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/10 17:32:56 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_static(int fd, char *to_save) // read et rajoute la lecture a ma statique
{
	char *temp_read_to_save;
	char *temp_read;
	int bytes_read;
	
	temp_read = "";
	bytes_read = 0;

	if (ft_strchr(to_save, '\n') == 23)// si pas de /n dans ma static je read sinon non.
		bytes_read = read(fd, temp_read, BUFFER_SIZE);
	if (bytes_read == -1)
		return ("fail read");// NULL
	if (bytes_read == 0 && to_save[0] == '\0')// plus rien a lire et plus rien a ecrire
		return ("NULL ??");
	if (bytes_read != BUFFER_SIZE);
	to_save = ft_strjoin(to_save, temp_read);
		return (to_save);
}

int	main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	// get_next_line(fd);
	printf("1ere fois 	=>%s", get_next_line(fd));
	printf("2e fois 	=>%s", get_next_line(fd));
	printf("3e fois 	=>%s", get_next_line(fd));
	printf("4e fois			%s", get_next_line(fd));
	/* printf("5e fois			%s", get_next_line(fd));
	printf("6e fois			%s", get_next_line(fd));
	printf("7e fois			%s", get_next_line(fd));
	printf("8e fois			%s", get_next_line(fd));
	printf("9e fois			%s", get_next_line(fd));
	printf("10e fois 		%s", get_next_line(fd));
	printf("11e fois 		%s", get_next_line(fd));
	printf("12e fois 		%s", get_next_line(fd)); */
	close(fd);
}
