/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:53:09 by gkoksal           #+#    #+#             */
/*   Updated: 2023/12/04 11:58:43 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;
	char			*s;

	if (!str)
		return (NULL);
	ch = (unsigned char) c;
	while (*str)
	{
		if ((unsigned char)*str == ch)
		{
			s = (char *)str;
			return (s);
		}
		str++;
	}
	if (ch == '\0')
	{
		s = (char *)str;
		return (s);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	n;

	if (!*s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	n = 0;
	while (s[n])
	{
		str[n] = s[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}

char	*ft_strjoin(char	*line, const char *buffer)
{
	char			*str;
	unsigned int	n;

	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (!str)
	{
		if (line)
			free(line);
		return (NULL);
	}
	n = 0;
	if (line)
	{
		while (line[n] != '\0')
		{
			str[n] = line[n];
			n++;
		}
	}
	free(line);
	while (*buffer)
		str[n++] = *buffer++;
	str[n] = '\0';
	return (str);
}

char	*free_mem(char *line, char *buffer)
{
	free(buffer);
	free(line);
	return (NULL);
}
