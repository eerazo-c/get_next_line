/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:31 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/21 16:01:47 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_clean(char **alloc_memory)
{
	if (alloc_memory && *alloc_memory)
	{
		free(*alloc_memory);
		*alloc_memory = NULL;
	}
	return (NULL);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

void	*ft_strchr(char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == (char)c)
		return ((char *)&string[i]);
	return (NULL);
}

char	*ft_strjoin(char *space, char *buffer)
{
	int		i;
	int		j;
	size_t	total_len;
	char	*new;

	if (space == NULL)
	{
		space = malloc(sizeof(char) + 1);
		if (!space)
			return (NULL);
		space[0] = '\0';
	}
	total_len = ft_strlen(space);
	new = malloc (sizeof(char) * (ft_strlen(buffer) + total_len + 1));
	if (!new)
		return (ft_clean(&space));
	i = -1;
	while (space[++i])
		new[i] = space[i];
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	ft_clean(&space);
	return (new);
}
