/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:38:13 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/08 15:07:26 by maxoph           ###   ########.fr       */
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

	while (i < BUFFER_SIZE)
	{
		//printf("str[i] = %c\n", str[i]);
		if (str[i] == '\n' && i == (BUFFER_SIZE - 1)) // on est au bout de la ligne // renvoi tout, pas de to_save / FIN 	666
			return (666); 
		else if (str[i] == '\n')  //on s'arrete en plein milieu ET on utilise i dans SUBSTR   		i =
			return(i);
		//else if (str[i] != '\0' && str[i] != '\n')
		i++;
		
	}
	return (777); //tout est bon, next
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*to_save = NULL; // MA STATIC a utiliser que lorsque \n
	char		*to_push; // resultat
	char		*newtemp;
	int x;
	int bytes_read;
	
	//if (!(to_save = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		//return ("fail_to_check");
	if (!(to_push = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return ("failpush");
	//if (to_save[0] == '\0')
	while (1)
	{
		if (!to_save)
		{
			temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
            if (!temp)
                return (NULL);
			bytes_read = read(fd, temp, BUFFER_SIZE);
    		if (bytes_read <= 0)
        		return (NULL);
    		temp[bytes_read] = '\0';
		}
		if (to_save)
		{
			newtemp = ft_strjoin(temp, to_save);
			temp = newtemp;
			free(to_save);
			//to_save = NULL;
		}
			
		
		//printf("counter = %d\n", counter);
		//printf("return de exam_to_check =%d", (exam_to_check(to_check)));
		if ((exam_to_check(temp)) == 777) //rajoute TOUT temp dans to_push si pas de \n 	OK
		{
			//printf("to_push avant = %s\n", to_push);
			to_push = ft_strjoin(to_push, temp); // copie check dans push
			//printf("to_push apres = %s\n", to_push);
		}
		else if ((exam_to_check(to_push = ft_strjoin(to_push, temp))) == 666) // on renvoi tout puis FIN
		{
			to_push = ft_strjoin(to_push, temp);
			//to_push = ft_strjoin(to_push, ft_substr(to_check, 0, counter));
			//to_check = &to_check[counter];
			return (to_push);
		}
		else if((exam_to_check(temp)) == -1) //erreur quitte tout
		{
			//printf("sors de la OMG\n");
			return ("CPASBON");
		}
		else																	// fin
		{
			//printf("sors de la\n");
			x = bytes_read + exam_to_check(temp);
			printf("emplacement du bakslashaine = %d\n", x);
			to_save = ft_substr(to_push, (x + 1), BUFFER_SIZE - (x));
			printf("to_save = %s\n", to_save);
			char *TEST = ft_substr(temp, 0, x);
			TEST[ft_strlen(TEST)] = '\0';
			//free(to_push);
			TEST = to_push;
			printf("to_push = %s\n", to_push);
			to_push[x] = '\0';
			printf("to_push apres = %s\n", to_push);
			return (to_push);
		}		
	}
	free(temp);
	return (to_push); // return toute ma str en 1x
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	get_next_line(fd);
	//printf("ma fonction renvoi =>%s\n", get_next_line(fd));
	//printf("et ensuite =>%s\n", get_next_line(fd));
	/* printf("3%s\n", get_next_line(fd));
	printf("4%s\n", get_next_line(fd));
	printf("5%s\n", get_next_line(fd));
	printf("6%s\n", get_next_line(fd));
	printf("7%s\n", get_next_line(fd)); */
	//7
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	close(fd);
}
