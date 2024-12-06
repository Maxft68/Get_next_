int	exam_to_check(char *str)// CHERCHE dans src \N si oui renvoi jusqua \n et garde le reste/ si non renvoi tout
{
	int i;
	i = 0;

	while (str[i])
	{
		//printf("str[i] = %c\n", str[i]);
		if (str[i] == '\n' && i == BUFFER_SIZE) // on est au bout de la ligne // renvoi tout / FIN
			return (666);
		else if (i == BUFFER_SIZE) //tout est bon on continue // on renvoi tout
			return(777); 
		else if (str[i] == '\n')  //on s'arrete en plein milieu ET on utilise i dans SUBSTR
			return(i);
		i++;
		//printf("i = %d\n", i);
	}
	return (-1); // \0 ??
}

char	*get_next_line(int fd)
{
	char		temp[BUFFER_SIZE + 1];
	static char	*to_check; // MA STATIC a utiliser que lorsque \n
	char		*to_push; // resultat
	int x;

	if (!(to_check = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return ("fail_to_check");
	if (!(to_push = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return ("failpush");
	while (1)
	{
		read(fd, temp, BUFFER_SIZE);
		//printf("counter = %d\n", counter);
		//printf("return de exam_to_check =%d", (exam_to_check(to_check)));
		if ((exam_to_check(to_check = ft_strjoin(to_check, temp))) == 777) //rajoute TOUT temp dans to_check si pas de \n 	OK
		{
			to_push = ft_strjoin(to_push, to_check); // copie check dans push
		}
		else if ((exam_to_check(to_check = ft_strjoin(to_check, temp))) == 666) // on renvoi tout puis FIN
		{
			to_push = ft_strjoin(to_push, to_check);
			//to_push = ft_strjoin(to_push, ft_substr(to_check, 0, counter));
			//to_check = &to_check[counter];
			return (to_push);
		}
		else if((exam_to_check(to_check = ft_strjoin(to_check, temp))) == -1) //erreur quitte tout
		{
			//printf("sors de la OMG\n");
			return (NULL);
		}
		else																	// fin
		{
			//printf("sors de la\n");
			x = exam_to_check(to_check = ft_strjoin(to_check, temp));
			//printf("counter = %d\n", counter);
			to_push = ft_strjoin(to_push, ft_substr(to_check, 0, x));
			//printf("x = %d\n", x);
			return (to_push);
		}		
	}
	return (to_push); // return toute ma str en 1x
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	//get_next_line(fd);
	printf("ma fonction renvoi:\n%s", get_next_line(fd));
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	//printf("ma fonction renvoi:\n%s", get_next_line(fd));
	close(fd);
}