/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:29:28 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/01/03 16:38:20 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <fcntl.h> // ?
#include <stddef.h>// ?
#include <stdio.h> // ?
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // ?

typedef struct var
{
	char *temp_read;
	char *temp_save;
	char *new_to_save;
	int newline_index;
	int bytes_read;
	char *line;
	char *start;
	char *temp;
} 	t_variable;

char 	*ft_separator(t_variable *v, char **to_save);
char	*get_next_line(int fd);
char	*extract_static(char *line, char **to_save);
char	*extract_line(int fd, char **to_save);
char	*maj_return_line(char **to_save);
void	free_all(char **s, char **s1);
char	*read_untill_newline(int fd, char *to_save);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif