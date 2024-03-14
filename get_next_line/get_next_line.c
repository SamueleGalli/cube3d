/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:12:20 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/14 14:40:26 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*get_next_line(int fd)
{
	ssize_t	line_len;
	int		found_newline;
	char	*line;

	line_len = 0;
	found_newline = 0;
	line = read_from_fd(fd, &line_len, &found_newline);
	if (line == NULL || (!found_newline && line_len == 0))
	{
		free(line);
		return (NULL);
	}
	if (line_len == 0 && line != NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*read_from_fd(int fd, ssize_t *line_len, int *found_newline)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*line;
	char	*newline_ptr;

	line = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		newline_ptr = ft_strchr(buffer, '\n');
		if (newline_ptr != NULL)
		{
			*line_len += newline_ptr - buffer;
			*found_newline = 1;
			break ;
		}
		else
			*line_len += bytes_read;
		line = append_buffer(line, buffer, bytes_read, line_len);
		if (line == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

static char	*append_buffer(char *line, char *buffer, ssize_t bytes_read,
		ssize_t *line_len)
{
	char	*tmp;

	tmp = malloc(*line_len + 1);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	if (line)
	{
		ft_strcpy(tmp, line);
		ft_strcat(tmp, buffer);
		free(line);
	}
	else
	{
		ft_strcpy(tmp, buffer);
	}
	return (tmp);
}
