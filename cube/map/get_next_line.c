/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:42:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/29 10:22:38 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_get_line(char *save)
{
	int		r;
	char	*stri;

	r = 0;
	if (save[r] == '\0')
		return (NULL);
	while (save[r] != '\0' && save[r] != '\n')
		r++;
	if (save[r] == '\n')
		r++;
	stri = (char *)malloc(sizeof(char) * (r + 1));
	r = 0;
	while (save[r] != '\0' && save[r] != '\n')
	{
		stri[r] = save[r];
		r++;
	}
	if (save[r] == '\n')
	{
		stri[r] = save[r];
		r++;
	}
	stri[r] = '\0';
	return (stri);
}

char	*ft_save(char *save)
{
	int		p;
	int		o;
	char	*st;

	p = 0;
	while (save[p] != '\0' && save[p] != '\n')
		p++;
	if (save[p] == '\0')
	{
		free(save);
		return (NULL);
	}
	st = (char *)malloc((sizeof(char) *(ft_strlen_g(save) - p + 1)));
	if (st == NULL)
		return (NULL);
	p++;
	o = 0;
	while (save[p] != '\0')
	{
		st[o++] = save[p++];
	}
	st[o] = '\0';
	free(save);
	return (st);
}

char	*ft_read_n_save(int fd, t_general *g)
{
	char	*buff;
	int		readb;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	readb = 1;
	while (ft_strchr(g->save, '\n') == 0 && readb != 0)
	{
		readb = read(fd, buff, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readb] = '\0';
		g->save = ft_strjoin(g->save, buff);
	}
	free(buff);
	return (g->save);
}

char	*get_next_line(int fd, t_general *g)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	g->save = ft_read_n_save(fd, g);
	if (g->save == NULL)
		return (NULL);
	line = ft_get_line(g->save);
	g->save = ft_save(g->save);
	return (line);
}
