/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/12 16:09:29 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define PG 3.14159265358979323846
#  define WHITE 0xFFFFFF
#  define RED 0xFF0000
#  define GREEN 0x00FF00
#  define BLUE 0x0000FF
#  define YELLOW 0xFFFF00
#  define CYAN 0x00FFFF
# endif

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

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
	int		size_obj;
	int		x;
	int		y;
	int		pl_x;
	int		pl_y;
	int		x_end;
	int		y_end;
	double	x_p;
	double	y_p;
	double	angle;
}			t_general;

void		draw_walls(t_general *g, int x, int y, int distance);
void		draw_floor(t_general *g, int x, int y, int distance);
void		draw_ceiling(t_general *g, int x, int y, int distance);
void		draw_floor(t_general *g, int x, int y, int distance);
void		init_game(t_general *g);
void		alloc_cube(t_general *g, int j);
void		alloc_map(t_general *g, int i);
void		copy_cubed(t_general *g);
void		free_matrix(char **mat);
void		recopy(t_general *g);
void		raycast(t_general *g);

size_t		ft_strlen_g(const char *s);

int			update_cube(t_general *g);
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
