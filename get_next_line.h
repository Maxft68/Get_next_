/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:29:28 by mdsiurds          #+#    #+#             */
/*   Updated: 2024/12/19 16:30:04 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

#include <fcntl.h> // ?
#include <stddef.h>// ?
#include <stdio.h> // ?
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // ?

char	*get_next_line(int fd);
//void    exit_and_free_all(char *to_push, char *to_save);
//char    *maj_save_push(char *to_push, char **to_save);
char *maj_return_line(char **to_save);
char    *free_all(char *s);
//char	*read_untill_newline(int fd, char *to_push, char *to_save);
char	*read_untill_newline(int fd, char *to_save);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
