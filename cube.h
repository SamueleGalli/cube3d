/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/14 14:54:42 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_general
{
	void	*mlx;
	int		i;
	char	**v;
	void	*win;
	int		fd;
}			t_general;

char		*read_from_fd(int fd, ssize_t *line_len, int *found_newline);
char		*append_buffer(char *line, char *buffer, ssize_t bytes_read, \
		ssize_t *line_len);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char *s, int start, int len);

int			ft_strcmp(char *s, char *s2);
int			check_error(char **v, int i);
int			ft_strlcpy(char *dest, char *src, int size);
int			ft_strlen(char *s);
int			manage_key(int key, t_general *g);
int			end_program(t_general *g);

void		init_game(t_general g);

#endif
