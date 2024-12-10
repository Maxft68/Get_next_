/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_OLD.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:38:13 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/10 17:16:15 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int	exam_to_check(char *str)// CHERCHE dans src \N si oui renvoi jusqua \n et garde le reste/ si non renvoi tout
{
	int i;
	int s;
	i = 0;
	s = ft_strlen(str);

	while (str[i] < s)
	{
		//printf("str[i] = %c\n", str[i]);
		/* if (str[i] == '\n' && i == (unsigned long)(ft_strlen(str) - 1)) // on est au bout de la ligne // renvoi tout, pas de to_save / FIN 	666
			return (666);  */
		if (str[i] == '\n')  //on s'arrete en plein milieu ET on utilise i dans SUBSTR   		i =
			return (i);
		
		else if (str[i] == '\0')
			return (000);
		i++;
		
	}
	return (777); //tout est bon, next  777 a remplacer au cas ou le /n est en 777place
}
int	ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != (char)c)
			i++;
		else
			return (23);
	}
	if (s[i] == (char)c)
		return (23);
	return (0);
}

char	*get_next_lineOLD(int fd)
{
	char		*temp;
	static char	*to_save = ""; // MA STATIC a utiliser que lorsque \n
	int	 	r = 0;
	char		*to_push; // resultat
	char 		*temp_read;
	int x;
	int bytes_read;
	temp = "";
	temp_read = "";
	if (!(temp = malloc((BUFFER_SIZE * 2) * sizeof(char))))
        return ("fail_to_check");
	//if (!(to_save = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		//return ("fail_to_check");
	if (!(to_push = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return ("failpush");
	
	//if (to_save == NULL)
		//to_save = "";
	if (to_save && to_save[0] != '\0')
	{
		printf("to_save = %s\n", to_save);
		printf("temp avant assignation = %s\n", temp);
		temp = ft_strjoin(to_save, temp);
	}
	while (r == 0)
	{
		if (!(temp_read = malloc((BUFFER_SIZE + 1) * sizeof(char))))
        	return ("fail_to_read");
		 if (r == 0)
		{
			bytes_read = read(fd, temp_read, BUFFER_SIZE);
			if (bytes_read != BUFFER_SIZE)
				r = 1;
			if (bytes_read == 0 && temp[0] == '\0')
				return (NULL);
		}
		temp = ft_strjoin(temp, temp_read);
		
		if ((exam_to_check(temp)) == 777) //rajoute TOUT temp dans to_push si pas de \n 	OK
		{
			to_push = ft_strjoin(to_push, temp); // copie check dans push
		}
		else if ((exam_to_check(to_push = ft_strjoin(to_push, temp))) == 666) // on renvoi tout puis FIN
			return (to_push = ft_strjoin(to_push, temp));
		else if((exam_to_check(temp)) == 000) // ya un \n
		{
			to_push = ft_strjoin(to_push, temp);
			free(temp);
			printf("FINI :D");
			return (NULL);
		}
		else																	// fin
		{
			//printf("sors de la\n");
			x = exam_to_check(temp);
			//printf("emplacement du bakslashaine = %d\n", x);
			to_save = ft_substr(temp, (x + 1), BUFFER_SIZE);
			//printf("to_save = %s\n", to_save);
			to_push = ft_substr(temp, 0, (x + 1));
			//printf("to_push = %s\n", to_push);
		
			return (to_push);
		}		
	}
	free(temp);
	return (to_push); // return toute ma str en 1x
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%i %s", i, line);
		i++;
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
} */

/* int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	//get_next_line(fd);
	printf("1ere fois 	=>%s", get_next_line(fd));
	printf("2e fois 	=>%s", get_next_line(fd));
	printf("3e fois 	=>%s", get_next_line(fd));
	printf("4e fois		  %s", get_next_line(fd));
	printf("5e fois		  %s", get_next_line(fd));
	printf("6e fois		  %s", get_next_line(fd));
	printf("7e fois		  %s", get_next_line(fd));
	printf("8e fois		  %s", get_next_line(fd));
	printf("9e fois		  %s", get_next_line(fd));
	printf("10e fois 	  %s", get_next_line(fd));
	printf("11e fois 	  %s", get_next_line(fd));
	printf("12e fois 	  %s", get_next_line(fd));
	close(fd);
} */
