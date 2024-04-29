/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:23 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/29 14:23:25 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	invalid_color(t_general *g)
{
	if (g->floor != 0 && g->sky != 0)
	{
		if (g->floor[0] != 0 && g->floor[1] != 0 && \
		g->floor[2] != 0 && g->sky[0] != 0 && g->sky[1] != 0 \
		&& g->sky[2] != 0)
		{
			if (ft_atoi(g->floor[0]) > 255 || ft_atoi(g->floor[1]) > 255 || \
			ft_atoi(g->floor[2]) > 255 || ft_atoi(g->sky[0]) > 255 \
			|| ft_atoi(g->sky[1]) > 255 || ft_atoi(g->sky[2]) > 255)
			{
				printf("Error\n(rgb color to large))\n");
				end_program(g);
			}
			return ;
		}
		else
		{
			printf("Error\n(invalid color)\n");
			end_program(g);
		}
	}
}

/*
(bpp) bit per pixel
(size_l) dimensione immagine
(endian) indica il modo in cui
i bit vengono memorizzati con un
valore numerico
*/
void	start_cube(t_general *g)
{
	init_game(g);
	invalid_color(g);
	g->posx = (double)g->py + 0.2f;
	g->posy = (double)g->px + 0.2f;
	g->mlx = mlx_init();
	buffer(g, 0, 0);
	texture(g);
	g->win = mlx_new_window(g->mlx, g->width, g->height, "cube3D");
	g->img = mlx_new_image(g->mlx, g->width, g->height);
	g->data = (int *)mlx_get_data_addr(g->img, &g->bpp, &g->size_l, &g->endian);
	mlx_loop_hook(g->mlx, update_cube, g);
	mlx_hook(g->win, 17, 1L << 17, end_program, g);
	mlx_key_hook(g->win, manage_key, g);
	mlx_loop(g->mlx);
}

void	alloc_g_cont(t_general *g)
{
	g->x = 0;
	g->y = 0;
	g->p_view = 0;
	g->dirx = -1.0;
	g->diry = 0.0;
	g->planex = 0.0;
	g->planey = 0.66;
	g->movespeed = 0.50;
	g->rotspeed = 0.20;
	g->save = 0;
	g->north = 0;
	g->south = 0;
	g->east = 0;
	g->west = 0;
}

void	alloc_g(t_general *g, int c, char **v)
{
	g->c = c;
	g->img = 0;
	g->v = v;
	g->j = 0;
	g->i_texture = 0;
	g->width = 700;
	g->height = 800;
	g->mlx = 0;
	g->invalid_sign = 0;
	g->invalid_maxp = 0;
	g->win = 0;
	g->l = 0;
	g->rebuf = 0;
	g->i = 0;
	g->buf = 0;
	g->sky = 0;
	g->floor = 0;
	g->texture = 0;
	g->tmp = 0;
	g->cubed = 0;
	alloc_g_cont(g);
}

int	main(int c, char **v)
{
	t_general	*g;

	g = malloc(sizeof(t_general));
	alloc_g(g, c, v);
	if (check_error(g->v, g->c) == 1)
	{
		if (g != 0)
			free(g);
		exit(1);
	}
	start_cube(g);
}
