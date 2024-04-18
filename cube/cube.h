/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:40:15 by sgalli           ###   ########.fr       */
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
#  define RED 0xFF0000
#  define GREEN 0x00FF00
#  define WU "image/Walls/WallD.xpm"
#  define WL "image/Walls/WallL.xpm"
#  define WR "image/Walls/WallR.xpm"
#  define WD "image/Walls/WallU.xpm"
#  define SKY "image/FloorSky/Sky.xpm"
#  define FLOOR "image/FloorSky/Floor.xpm"
# endif

# include "minilibx-linux/mlx.h"
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
	int		**buf;
	int		**texture;
	int		*data;
	char	*l;
	void	*mlx;
	void	*win;
	void	*img;
	char	p_view;
	int		width;
	int		height;
	int		c;
	int		rebuf;
	int		j;
	int		fd;
	int		x;
	int		y;
	int		px;
	int		py;
	int		x_end;
	int		y_end;
	int		color;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		texnum;
	int		texx;
	int		texy;
	int		bpp;
	int		size_l;
	int		endian;
	int		img_width;
	int		img_height;
	double	wallx;
	double	step;
	double	texpos;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movespeed;
	double	rotspeed;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	perpwalldistx;
	double	lineheight;
	double	drawstart;
	double	drawend;
}			t_general;

void		buffer(t_general *g, int i, int j);
void		texture(t_general *g);
void		painting(t_general *g, int x);
void		go_south(t_general *g);
void		go_north(t_general *g);
void		go_east(t_general *g);
void		go_west(t_general *g);
void		initialize_ray(t_general *g, int i);
void		checking_ray(t_general *g);
void		hitting(t_general *g);
void		distance(t_general *g);
void		init_game(t_general *g);
void		alloc_cube(t_general *g, int j);
void		alloc_map(t_general *g, int i);
void		copy_cubed(t_general *g);
void		free_matrix(char **mat);
void		recopy(t_general *g);

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
