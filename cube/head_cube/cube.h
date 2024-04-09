/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/09 13:00:57 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
N = NORD
S = SUD
E = EST
W = WEST
*/

typedef struct s_general
{
	char	**tmp;
	char	**v;
	char	**cubed;
	char	*l;
	void	*mlx;
	void	*win;
	char	p_view;
	int		width;
	int		height;
	int		i;
	int		fd;
	int		x;
	int		y;
	int		x_p;
	int		y_p;
	int		x_end;
	int		y_end;
}			t_general;

void		init_game(t_general *g);
void		alloc_cube(t_general *g, int j);
void		alloc_map(t_general *g, int i);
void		copy_cubed(t_general *g);
void		free_matrix(char **mat);
void		recopy(t_general *g);

size_t		ft_strlen_g(const char *s);

int			draw_map(t_general *g);
int			ft_mat_len(char **mat);
int			ft_strcmp(char *s, char *s2);
int			check_error(char **v, int i);
int			ft_strlcpy(char *dest, char *src, int size);
int			ft_strlen(char *s);
int			manage_key(int key, t_general *g);
int			end_program(t_general *g);
int			getting_line(t_general *g, int i);
int			is_valid(t_general *g);
int			end_mat(char **mat);

char		*ft_substr(char *s, int start, int len);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *b);
char		*ft_strchr(char *t, int c);
char		*ft_get_line(char *save);
char		*ft_save(char *save);
char		*ft_read_n_save(int fd, char *save);
#endif
