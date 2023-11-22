/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:37 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/22 15:15:29 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int main ()
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
