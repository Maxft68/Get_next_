/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:48:34 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/01/02 14:07:07 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(char	**s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
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
			return (i);
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}
char *get_next_line(int fd)
{
	static char *to_save = NULL;
	char *temp_read;
	char *temp_save;
	int bytes_read;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 ||
	!(temp_read = malloc((BUFFER_SIZE + 1) * sizeof(char))))
	{
		free_all(&to_save);
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if ((bytes_read = read(fd, temp_read, BUFFER_SIZE)) < 0)
		{
			free_all(&temp_read);
			free_all(&to_save);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		temp_read[bytes_read] = '\0';
		//to_save = ft_strjoin(to_save, temp_read);
		temp_save = ft_strjoin(to_save, temp_read);
		free_all(&to_save);
		to_save = temp_save;
		if (ft_strchr(temp_read, '\n') != -1)
			break;
	}
	free_all(&temp_read);
	if (!to_save || !*to_save)
		return (NULL);
	int newline_index = ft_strchr(to_save, '\n');
	if (newline_index == -1)
	{
		line = to_save;
		to_save = NULL;
		return (line);
	}
	line = ft_substr(to_save, 0, newline_index + 1);
	if (!line)
	{
		free_all(&temp_read);
		free_all(&to_save);
		return (NULL);
	}
	char *new_to_save = NULL;
	if (to_save[newline_index + 1] != '\0')
	{
		char *start = &to_save[newline_index + 1];
		char *temp = start;
		/* size_t len = 0;
		
		while (*temp++)
			len++; */
		
		new_to_save = malloc(((ft_strlen(temp)) + 1) * sizeof(char));
		if (!new_to_save)
		{
			free_all(&line);
			free_all(&to_save);
			return (NULL);
		}
		ft_strlcpy(new_to_save, start, ft_strlen(temp) + 1);
	}
	free_all(&to_save);
	to_save = new_to_save;
	return (line);
}

/* #include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
		i++;
	return (i);
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
			return (i);
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}
char *ft_realoc(char *oldstr, int oldsize, int newsize) // a la place de strjoin
{
	char *newstr;

	if (newsize > oldsize)
	{
		newstr = malloc(newsize * sizeof(char));
		if (!newstr)
			return (NULL);
		free_all(oldstr);
		return (newstr);		
	}
	else
		return (oldstr);
}
char	*free_all(char	*s)
{
	free(s);
	s = NULL;
	return (NULL);
}

char	*read_untill_newline(int fd, char *to_save)
{
	char *str;
	int index_buffer;
	int bytes_read;
	char *temp_read;
	int index_str;

	if (index_buffer == 0) //rien lu encore
    {
        bytes_read = read(fd, temp_read, BUFFER_SIZE); 
		str = realloc(str, ft_strlenstr, ft_strlen(str) + bytes_read); //realloc pour nouvelle taille
		if (bytes_read < 0) // echec de lecture
			return (NULL);
		if (bytes_read == 0)
		{
			if (index_str !)
		}
		
	}

char *maj_return_line(char **to_save)
{
	
}

char *get_next_line(int fd)
{
	char *to_push;
	static char *to_save = NULL;
	
	to_push = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(to_save, '\n') != -1)
	to_save = read_untill_newline(fd, to_save);
	if (!to_save)
		return(NULL);
}

int main(void)
{
    char *line;
    int fd;
	int i;

    fd = open("empty.txt", O_RDONLY);
    i = 1;
    while (i < 2)
    {
        line = get_next_line(fd);
		printf("APPEL%d =%s\n",i++, line);
        free(line);
    }
    close(fd);
    return(0);
} */