/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:38:13 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/05 16:00:04 by mdsiurds         ###   ########.fr       */
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
	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (666);
		/* if (str[i + 1] == '\0')
			return (777); */
		i++;
	}
	return (999);
}

char	*get_next_line(int fd)
{
	char		temp[BUFFER_SIZE + 1];
	static char	*to_check; // MA STATIC 
	char		*to_push;
	int			counter;

	counter = 0;
	if (!(to_check = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return ("fail_to_check");
	if (!(to_push = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return ("failpush");
	while (666) //tant qu'il lis plus rien  ??
	{
		//printf("Test temp");
		counter = read(fd, temp, BUFFER_SIZE);
		if ((exam_to_check(to_check = ft_strjoin(to_check, temp))) == 999) //rajoute temp dans to_check et regarde si pas de \n
		{
			to_push = ft_strjoin(to_push, to_check); // copie check dans push
		//printf("Test temp: %s\n", to_push);	
		//printf("Test temp: %s\n", temp);
		printf("counter =%d\n", counter);
		}
		if ((exam_to_check(to_check = ft_strjoin(to_check, temp))) == 666) // IL FAUDRA SUBSTR a partir du /n
		{
			
			
			return (to_push);
		}
		
	}
	return (to_push); // return toute ma str en 1x REMETTRE TO_PUSH ENSUITE
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	//get_next_line(fd);
	printf("ma fonction renvoi:\n%s", get_next_line(fd));
	close(fd);
}
