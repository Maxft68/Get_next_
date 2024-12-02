/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:38:13 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/02 16:40:43 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	exam_the_temp(char *str)
// CHERCHE dans src \N si oui renvoi jusqua \n et garde le reste/ si non renvoi tout
{
	int i;
	i = 0;
	
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\n')
			return (666);
	 if (str[i + 1] == '\0')
	     return (777);
	}
	return (999);
}

char	*ft_strlcat_two(char *dst, char *src, size_t size) // strjoin
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	size = BUFFER_SIZE;
	while (dst[i])
		i++;
	while (BUFFER_SIZE >= x || src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
		x++;
	}
	
	return (dst);
}

char	*get_next_line(int fd)
{
	char		*to_push;
	static char	*str_temp;
	int i;

	to_push = malloc((BUFFER_SIZE + 1) * sizeof(char));
	str_temp = malloc((BUFFER_SIZE + 1)* sizeof(char));
	i = 0;
	if (!str_temp)
		return ("fail");
	
	//printf("Test APRES STRLCAT5465");
	//printf("valeur de retour de exam the temp :%d\n", exam_the_temp(str_temp));
	while (read(fd, str_temp, BUFFER_SIZE) == BUFFER_SIZE )//(exam_the_temp(str_temp)) != 777) //777 = Jackpot on continue || 666 = '\n' dans le buffer || 999 == FINI
	{
		//printf("Test APRES STRLCAT55");
		read(fd, str_temp, BUFFER_SIZE);
		exam_the_temp(str_temp);
		//if ((exam_the_temp(str_temp)) == 777)
		//{
			//printf("Test str temp: %s\n", str_temp);
			//printf("Test to_push: %s\n", to_push);
			//printf("Test to_push APRES STRLCAT: %s\n", to_push);
			//printf("Test APRES STRLCAT");
			
			ft_strlcat_two(to_push, str_temp, BUFFER_SIZE);  // to_push = str_temp;
			//write(1, to_push, strlen(to_push));
		//}
		//printf("Test valeur FD:%d\n", fd);
		//printf("Test str temp: %s\n", str_temp);
		i++;
	}
	return (to_push); //return toute ma str en 1x
}

int	main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	//get_next_line(fd);
	printf("ma fonction renvoi: %s", get_next_line(fd));
	close(fd);
}

//
// essayer fonction   size_t read(int fd, void *buf, size_t nbytes)
// fonction open
// str temp => strcat dans str