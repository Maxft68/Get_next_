/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:58:33 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/19 17:02:56 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != (char)c)
			i++;
		else
			return (i);
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

/* void exit_and_free_all(char *to_push, char *to_save)
{
	if (to_push)
	{
		free(to_push);
		to_push = NULL;
	}
	if (to_save)
	{
		free(to_save);
		to_save = NULL;
	}
} */

char	*free_all(char	*s)
{
	free(s);
	s = NULL;
	return (NULL);
}

/* char *maj_save_push(char *to_push, char **to_save)
{
	int x;
	int n;
	
	x = ft_strchr(to_push, '\n');
	if (x == -1)
        return (to_push);
	n = ft_strlen(to_push) - x;
	
	*to_save = ft_substr(to_push, (x + 1), ft_strlen(to_push) - (x + 1));
	to_push = ft_substr(to_push, 0, x + 1);
	//printf("to_push1=%s", to_push);
	return (to_push);
} */

char *maj_return_line(char **to_save)
{
	int		x;
	char	*to_push;
	char	*new_save;
	
	x = ft_strchr(*to_save, '\n');
	if (x == -1)
        return (*to_save);
	to_push = malloc(sizeof(char) * x + 2);
	if (!to_push)
		return free_all(to_push);

	new_save = malloc(sizeof(char) * ft_strlen(*to_save - x + 1));
	if (!new_save)
		return(free_all(new_save), NULL);
	new_save = ft_substr(*to_save, (x + 1), ft_strlen(*to_save) - x);
	to_push = ft_substr(*to_save, 0, x + 1);
	//ft_strlcpy(new_save, *to_save + x + 1, ft_strlen(*to_save - x + 1));
	free_all(*to_save);
	*to_save = ft_strdup(new_save);
	free_all(new_save);
	return (to_push);
}
/* char	*read_untill_newline(int fd, char *to_push, char *to_save)
{
	int bytes_read;
	char *temp_read;

	bytes_read = 1;
	while (bytes_read > 0 && (ft_strchr(to_push, '\n') == -1))
	{
		temp_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
		bytes_read = read(fd, temp_read, BUFFER_SIZE);
		if (bytes_read < 0) // cas derreur de read
		{
			return(free_all(to_push)); //free tout ce qui a ete malloc
		}
		temp_read[bytes_read] = '\0';
		to_push = ft_strjoin(to_push, temp_read);
		free(temp_read);
	}
	return (to_push);
} */

char	*read_untill_newline(int fd, char *to_save)
{
	int bytes_read;
	char *temp_read;

	bytes_read = 1;
	while (bytes_read > 0 && (ft_strchr(to_save, '\n') == -1))
	{
		temp_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!temp_read)
			return (NULL);
		bytes_read = read(fd, temp_read, BUFFER_SIZE);
		if (bytes_read < 0) // cas derreur de read
		{
			free_all(temp_read);
			//free tout ce qui a ete malloc
		}
	 	if (temp_read[0] == '\0')
		{
			to_save = NULL;
			return (NULL);
		}
		temp_read[bytes_read] = '\0';
		printf("temp=%s\n",temp_read);
		to_save = ft_strjoin(to_save, temp_read);
		printf("temp=%s\n",temp_read);
		printf("to_save=%s\n",to_save);
		//if (temp_read[0] == '\0')
		//	return(NULL);
		free(temp_read);
	}
	return (to_save);
}
char *get_next_line(int fd)
{	
	//int i = 1;

	char *to_push;
	static char *to_save = "";
	
	to_push = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	to_save = read_untill_newline(fd, to_save);
	if (!to_save)
		return(NULL);
	
	to_push = maj_return_line(&to_save);
	return (to_push);
}
/* char *get_next_line(int fd)
{	
	//int i = 1;

	char *to_push;
	static char *to_save = NULL;
	char *tmp;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	to_push = ft_strdup("");
	if (to_save == NULL || ft_strchr(to_save, '\n') == -1) //premier appel
    {
		//int i = 100;
		//printf("to_save%d=%s\n", i++, to_save);
        to_push = read_untill_newline(fd, to_push, to_save);
		//printf("to_push %s\n", to_push);
        if (to_push == NULL)
			return (exit_and_free_all(to_push, to_save), NULL);
    }
	if (to_save != NULL) //&& ft_strchr(to_save, '\n') != -1) //si to_save non NULL alors je fou dans to_push
	{
		//printf("toto\n");
		to_push = maj_save_push(to_push, &to_save);
		//printf("to save %s\n",to_save);
	}
	
	else
	{
		//printf("to_save1/%d=%s\n", i++, to_save);
		to_push = read_untill_newline(fd, to_push, to_save); 
		if (to_push == NULL)
			return (free(to_push), NULL);
		//printf("to_save2/%d=%s\n", i++, to_save);
		//printf("to_push2/%d=%s\n", i++, to_push);
		if (ft_strchr(to_push, '\n') != -1)
		{
		tmp = maj_save_push(to_push, &to_save); //extrait le /n
		//printf("to_save3/%d=%s\n", i++, to_save);
		free(to_push); //free lancien
		to_push = tmp; //actualise to_push
		//free(tmp);
		}
	}
	if (to_push && to_push[0] == '\0')
	{
		return (NULL);
	}
	
	//printf("to_save4/%d=%s\n", i++, to_save);
	return (to_push);
} */


char *reaaloc(*ancientstr,int anciensize, int nouveausize)
{
	char *nouveau;
	si ("le nouveau est superieur a l'ancien")
	{
		malloc(taillede(char) * nouveau);
	}
	copie("ancien vers nouveau")

	libere(ancien)
	retourne nouveau;
}