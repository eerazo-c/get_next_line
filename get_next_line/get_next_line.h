/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:13 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/21 14:50:12 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# <biblioteca.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//funciones prototipo
char	*get_next_line(int fd);
char	*up_date(char	*space);
char	*extract_line(char *space);
char	*ft_read(int fd, char *space);
//funciones utils
size_t	ft_strlen(const char *string);
void	*ft_clean(char **alloc_memory);
void	*ft_strchr(char *string, int c);
char	*ft_strjoin(char *space, char *buffer);

#endif
