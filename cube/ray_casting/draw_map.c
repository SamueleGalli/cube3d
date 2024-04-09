/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:17 by sgalli            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/09 14:59:23 by sgalli           ###   ########.fr       */
=======
/*   Updated: 2024/04/09 13:01:22 by sgalli           ###   ########.fr       */
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

<<<<<<< HEAD
void	draw_floor(t_general *g)
=======
void	map_raycasting(t_general *g)
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
{
	int	i;

	i = 0;
<<<<<<< HEAD
	while (i < 20)
	{
		mlx_pixel_put(g->mlx, g->win, g->x * g->size_obj + i, \
		g->y * g->size_obj + i, 0x00FF0000);
		i++;
	}
}

void	draw_wall(t_general *g)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		mlx_pixel_put(g->mlx, g->win, g->x * g->size_obj + i, \
		g->y * g->size_obj + i, 0x0000F000);
		i++;
	}
}

void	draw_player(t_general *g)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		mlx_pixel_put(g->mlx, g->win, g->x * g->size_obj + i, \
		g->y * g->size_obj + i, 0xFF0F0FF);
		i++;
	}
}

void	map_raycasting(t_general *g)
{
	fov(g);
	if (g->cubed[g->y][g->x] == '0')
		draw_floor(g);
	else if (g->cubed[g->y][g->x] == '1')
		draw_wall(g);
	if (g->cubed[g->y][g->x] == 'N' || g->cubed[g->y][g->x] == 'S' ||
		g->cubed[g->y][g->x] == 'E' || g->cubed[g->y][g->x] == 'W')
		draw_player(g);
}

=======
	if (g->cubed[g->y][g->x] == '0')
	{
		//printf("pavimento\n");
		while (i < 20)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * 60 + i, g->y * 60 + i, 0x00FF0000);
			i++;
		}
		//draw_floor(g);
	}
	else if (g->cubed[g->y][g->x] == '1')
	{
		while (i < 20)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * 60 + i, g->y * 60 + i, 0x0000F000);
			i++;
		}
		//printf("muro\n");
		//draw_wall(g);
	}
	if (g->cubed[g->y][g->x] == 'N' || g->cubed[g->y][g->x] == 'S' || \
		g->cubed[g->y][g->x] == 'E' || g->cubed[g->y][g->x] == 'W')
	{
		while (i < 20)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * 60 + i, g->y * 60 + i, 0xFF0F0FF);
			i++;
		}
		//printf("buono\n");
	}
}

>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
int	draw_map(t_general *g)
{
	g->x = 0;
	g->y = 0;
	while (g->cubed[g->y] != 0)
	{
		while (g->cubed[g->y][g->x] != 0)
		{
			map_raycasting(g);
			g->x++;
		}
		g->x = 0;
		g->y++;
	}
	return (0);
}
