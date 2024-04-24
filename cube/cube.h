/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/24 15:33:46 by sgalli           ###   ########.fr       */
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
	int		**sky;
	int		**floor;
	int		*data;
	char	*l;
	char	**coordinate;
	void	*mlx;
	void	*win;
	void	*img;
	char	p_view;
	int		width;
	int		height;
	int		rebuf;
	int		j;
	int		fd;
	int		c;
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
	int		texx;
	int		texy;
	int		bpp;
	int		invalid_sign;
	int		invalid_maxp;
	int		size_l;
	int		endian;
	int		img_width;
	int		img_height;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
	int		floortexture;
	int		ceilingtexture;
	int		p;
	int		floortexx;
	int		floortexy;
	int		checkerboardpattern;
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
	double	floorxwall;
	double	floorywall;
	double	distwall;
	double	distplayer;
	double	currentdist;
	double	weight;
	double	currentfloorx;
	double	currentfloory;
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	float	posz;
	float	rowdistance;
	float	floorstepx;
	float	floorstepy;
	float	floorx;
	float	floory;
}			t_general;

void		flooring(t_general *g);
void		ceiling(t_general *g);
void		coordinate(t_general *g);
void		floor_casting(t_general *g, int x);
void		floor_cel_casting(t_general *g);
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
void		check_max_p(t_general *g, int i);
void		check_invalid_char(t_general *g, int i);
void		recopy(t_general *g);
size_t		ft_strlen_g(const char *s);

int			map_error(t_general *g);
int			update_cube(t_general *g);
int			ft_mat_len(char **mat);
int			ft_strcmp(char *s, char *s2);
int			check_error(char **v, int i);
int			ft_strlcpy(char *dest, char *src, int size);
int			ft_strlen(char *s);
int			manage_key(int key, t_general *g);
int			end_program(t_general *g);
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
