/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:50:02 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/17 14:51:39 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

/*
allocazione elementi
buffer a 0
*/
void	buffer(t_general *g, int i, int j)
{
	g->buf = (int **)malloc(sizeof(int *) * g->height);
	while (i < g->height)
		g->buf[i++] = (int *)malloc(sizeof(int) * g->width);
	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			g->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	load_img(t_general *g, int *texture, char *path)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	g->img = mlx_xpm_file_to_image(g->mlx, path, &g->img_width, &g->img_height);
	g->data = (int *)mlx_get_data_addr(g->img, &g->bpp, &g->size_l, &g->endian);
	while (y < g->img_height)
	{
		while (x < g->img_width)
		{
			texture[g->img_width * y + x] = g->data[g->img_width * y + x];
			x++;
		}
		y++;
		x = 0;
	}
	mlx_destroy_image(g->mlx, g->img);
}

/*
ciclo texture
*/
void	texture(t_general *g, int x, int y)
{
	while (x < 8)
	{
		y = 0;
		while (y < 64 * 64)
			g->texture[x][y++] = 0;
		x++;
	}
	load_img(g, g->texture[0], WALL_UP);
	load_img(g, g->texture[1], WALL_DOWN);
	load_img(g, g->texture[2], WALL_LEFT);
	load_img(g, g->texture[3], WALL_RIGHT);
	load_img(g, g->texture[4], WALL_RIGHT);
	load_img(g, g->texture[5], WALL_LEFT);
	load_img(g, g->texture[6], WALL_UP);
	load_img(g, g->texture[7], WALL_DOWN);
}
