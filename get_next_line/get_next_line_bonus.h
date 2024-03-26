/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:57:49 by gkoksal           #+#    #+#             */
/*   Updated: 2023/12/04 12:07:51 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAXFD
#  define MAXFD 1024
# endif
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char	*line, const char *buffer);
char	*free_mem(char *line, char *buffer);
char	*read_file(char *line, int fd);
char	*get_remaining(char *line);
char	*get_next_line(int fd);

#endif
