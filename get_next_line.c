/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:58:33 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/16 19:50:32 by mdsiurds         ###   ########.fr       */
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

char *split_save_push(char *to_push, char **to_save)
{
	int x;
	
	x = ft_strchr(to_push, '\n');
	*to_save = ft_substr(to_push, (x + 1), ft_strlen(to_push));
	to_push = ft_substr(to_push, 0, x);
	return (to_push);
}
char	*load_untill_line(int fd, char *to_push, char *to_save)
{
	int bytes_read;
	char temp_read[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read >= 0 && (ft_strchr(to_push, '\n') != -1))
	{
		bytes_read = read(fd, temp_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			exit_and_free_all(to_push, to_save); //free tout ce qui a ete malloc et return null
		}
		temp_read[bytes_read] = '\0';
		to_push = ft_strjoin(to_push, temp_read);
	}
	return (to_push);
}

char *get_next_line(int fd)
{

	char *to_push;
	static char *to_save = NULL;
	char *tmp;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	to_push = ft_strdup("");
	if (ft_strchr(to_save, '\n') != -1)
		to_push = split_save_push(to_push, &to_save);
	else
	{
		to_push = load_untill_line(fd, to_push, to_save);
		tmp = split_save_push(to_push, &to_save);
		free(to_push);
		to_push = tmp; 
	}
	if (to_push[0] == '\0')
	{
		free(to_push);
		to_push = NULL;
	}
	return (to_push);
}
