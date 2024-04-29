/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:50:02 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/29 15:23:30 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
			g->buf[i][j++] = 0;
		i++;
	}
}

void	init_texture(t_general *g, char *path)
{
	if (g->i_texture == 0)
		g->texture = (int **)malloc(sizeof(int *) * 4);
	if (path == 0)
	{
		printf("Error\n(invalid path)\n");
		end_program(g);
	}
	g->img = mlx_xpm_file_to_image(g->mlx, path, &g->img_width, &g->img_height);
	if (g->img == NULL)
	{
		printf("Error\n(invalid image)\n");
		end_program(g);
	}
	g->texture[g->i_texture] = (int *)malloc(sizeof(int) * \
	(g->img_width * g->img_height));
	g->data = (int *)mlx_get_data_addr(g->img, &g->bpp, &g->size_l, &g->endian);
}

/*
(mlx_xpm_file_to_image) carica immagine
(mlx_get_data_addr) ottiene dati immagine
copia i dati dell'immagine nell'array texture
(mlx_destroy_image) elimina immagine
*/
void	load_img(t_general *g, char *path)
{
	int	y;
	int	x;

	init_texture(g, path);
	y = 0;
	while (y < g->img_height)
	{
		x = 0;
		while (x < g->img_width)
		{
			g->texture[g->i_texture][g->img_width * y + x] = \
			g->data[g->img_width * y + x];
			x++;
		}
		y++;
		x = 0;
	}
	g->i_texture++;
	mlx_destroy_image(g->mlx, g->img);
}

/*
ciclo texture
alloco le 6 texture
alloco memoria texture[i][j]
la inizzializzo a 0
le carico e salvo la immagine raccolta in texture
*/
void	texture(t_general *g)
{
	if (g->floor == 0 || g->sky == 0)
	{
		printf("Error\n(missing floor/sky color)\n");
		end_program(g);
	}
	if (g->east == 0 || g->south == 0 || g->west == 0 || g->north == 0)
	{
		printf("Error\n(missing coordinate/s)\n");
		end_program(g);
	}
	else
	{
		load_img(g, g->north);
		load_img(g, g->south);
		load_img(g, g->east);
		load_img(g, g->west);
	}
}
