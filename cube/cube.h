/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/07 12:58:38 by sgalli           ###   ########.fr       */
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
	char	**sky;
	char	**floor;
	int		**buf;
	int		**texture;
	int		*data;
	char	*l;
	char	*save;
	char	*east;
	char	*south;
	char	*west;
	char	*north;
	void	*mlx;
	void	*win;
	void	*img;
	char	p_view;
	int		width;
	int		height;
	int		rebuf;
	int		filled;
	int		j;
	int		i;
	int		max_line;
	int		fd;
	int		c;
	int		x;
	int		size_mat;
	int		y;
	int		px;
	int		py;
	int		check_fc;
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
	int		i_fc;
	int		i_cube;
	int		i_texture;
	int		max_len;
	int		in;
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
	double	lineheight;
	double	drawstart;
	double	drawend;
}			t_general;

void		new_line_or_space(t_general *g);
void		mapping(t_general *g, int max);
void		escape_space(t_general *g);
void		cont_alloc_map(t_general *g, int i);
void		map_validity(t_general *g);
void		east(t_general *g);
void		standard_lenght(t_general *g, int i);
void		north(t_general *g);
void		south(t_general *g);
void		west(t_general *g);
void		ceiling(t_general *g);
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
void		invalid_color(t_general *g);
void		free_matrix(char **mat);
void		check_max_p(t_general *g, int i);
void		check_invalid_char(t_general *g, int i);
void		recopy(t_general *g);
void		other_color(t_general *g, int t);
void		flooring(t_general *g);

size_t		ft_strlen_g(const char *s);

int			ft_atoi(const char *str);
int			getting_line(t_general *g, int i);
int			flood_fill(t_general *g, int j, int i);
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
int			check_newline(char *l);
int			checking_1_0(t_general *g);
int			check_f(t_general *g, int j, int i);

char		*ft_substr(char *s, int start, int len);
char		*get_next_line(int fd, t_general *g);
char		*ft_strjoin(char *s1, char *b);
char		*ft_strchr(char *t, int c);
char		*ft_get_line(char *save);
char		*ft_save(char *save);
char		*ft_read_n_save(int fd, t_general *g);
#endif
