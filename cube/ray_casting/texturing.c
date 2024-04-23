/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:50:02 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/23 11:02:51 by sgalli           ###   ########.fr       */
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

/*
(mlx_xpm_file_to_image) carica immagine
(mlx_get_data_addr) ottiene dati immagine
copia i dati dell'immagine nell'array texture
(mlx_destroy_image) elimina immagine
*/
void	load_img(t_general *g, int *texture, char *path)
{
	int	y;
	int	x;

	y = 0;
	g->img = mlx_xpm_file_to_image(g->mlx, path, &g->img_width, &g->img_height);
	g->data = (int *)mlx_get_data_addr(g->img, &g->bpp, &g->size_l, &g->endian);
	while (y < g->img_height)
	{
		x = 0;
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
alloco le 6 texture
alloco memoria texture[i][j]
la inizzializzo a 0
le carico e salvo la immagine raccolta in texture
*/
void	texture(t_general *g)
{
	int	i;
	int	j;

	g->texture = (int **)malloc(sizeof(int *) * 6);
	i = 0;
	while (i < 6)
	{
		g->texture[i] = (int *)malloc(sizeof(int) * (100 * 100));
		j = 0;
		while (j < 100 * 100)
			g->texture[i][j++] = 0;
		i++;
	}
	load_img(g, g->texture[0], WU);
	load_img(g, g->texture[1], WL);
	load_img(g, g->texture[2], WR);
	load_img(g, g->texture[3], WD);
	load_img(g, g->texture[4], FLOOR);
	load_img(g, g->texture[5], SKY);
}
