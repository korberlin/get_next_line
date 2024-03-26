/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:52:15 by gkoksal           #+#    #+#             */
/*   Updated: 2023/12/04 11:59:37 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(char *line, int fd)
{
	ssize_t	nbyte;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_mem(line, buffer));
	while (!ft_strchr(line, '\n'))
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (free_mem(line, buffer));
		if (nbyte == 0)
			break ;
		buffer[nbyte] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_remaining(char *line)
{
	char	*nextline;
	char	*remaining;

	nextline = ft_strchr(line, '\n');
	if (nextline)
	{
		nextline++;
		remaining = ft_strdup(nextline);
		*nextline = '\0';
	}
	else
		remaining = NULL;
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining[MAXFD];
	char		*line;

	line = read_file(remaining[fd], fd);
	remaining[fd] = get_remaining(line);
	return (line);
}
