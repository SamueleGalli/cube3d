/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/15 12:57:04 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_general
{
	char	**v;
	char	**cubed;
	char	*l;
	void	*mlx;
	void	*win;
	int		i;
	int		fd;
}			t_general;

void		init_game(t_general g);

size_t		ft_strlen_g(const char *s);

int			ft_strcmp(char *s, char *s2);
int			check_error(char **v, int i);
int			ft_strlcpy(char *dest, char *src, int size);
int			ft_strlen(char *s);
int			manage_key(int key, t_general *g);
int			end_program(t_general *g);

char		*ft_strdup(char *s);
char		*ft_substr(char *s, int start, int len);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *b);
char		*ft_strchr(char *t, int c);
char		*ft_get_line(char *save);
char		*ft_save(char *save);
char		*ft_read_n_save(int fd, char *save);

#endif
