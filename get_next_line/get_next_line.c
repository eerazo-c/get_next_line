/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:51:28 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/21 16:19:48 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*up_date(char *space)
{
	int		i;
	int		j;
	int		log_cad;
	char	*new_spa;

	if (space == NULL)
		return (NULL);
	i = 0;
	while (space[i] != '\n' && space[i] != '\0')
		i++;
	if (space[i] == '\0')
		return (ft_clean(&space));
	log_cad = ft_strlen(space);
	new_spa = malloc(sizeof(char) * (log_cad - i) + 1);
	if (!new_spa)
		return (ft_clean(&space));
	j = 0;
	while (space[i] != '\0')
		new_spa[j++] = space[++i];
	new_spa[j] = '\0';
	free(space);
	return (new_spa);
}

char	*extract_line(char *space)
{
	char	*line;
	int		i;
	int		j;

	if (space == NULL)
		return (NULL);
	if (!space[0])
		return (NULL);
	i = 0;
	while (space[i] != '\n' && space[i] != '\0')
		i++;
	if (space[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = space[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *space)
{
	long	le_bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_clean(&space));
	buffer[0] = '\0';
	le_bytes = 1;
	while (le_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		le_bytes = read(fd, buffer, BUFFER_SIZE);
		if (le_bytes == -1)
		{
			free(buffer);
			return (ft_clean(&space));
		}
		if (le_bytes > 0)
		{
			buffer[le_bytes] = '\0';
			space = ft_strjoin(space, buffer);
		}
	}
	free(buffer);
	return (space);
}

char	*get_next_line(int fd)
{
	static char	*space = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(space);
		space = NULL;
		return (NULL);
	}
	space = ft_read(fd, space);
	if (space == NULL)
		return (NULL);
	next_line = extract_line(space);
	if (!next_line)
		return (ft_clean(&space));
	space = up_date(space);
	return (next_line);
}
