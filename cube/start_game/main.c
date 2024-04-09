/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:23 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/09 12:59:39 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	start_cube(t_general *g)
{
	init_game(g);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->width, g->height, "cube3D");
	mlx_hook(g->win, 17, 1L << 17, end_program, g);
	mlx_key_hook(g->win, manage_key, g);
	mlx_loop_hook(g->mlx, draw_map, g);
	mlx_loop(g->mlx);
}

void	alloc_g(t_general *g, int c, char **v)
{
	g->i = c;
	g->v = v;
	g->l = NULL;
	g->tmp = NULL;
	g->cubed = NULL;
	g->mlx = 0;
	g->y_p = 0;
	g->x = 0;
	g->p_view = 0;
	g->y = 0;
	g->width = 800;
	g->height = 600;
	g->x_p = 0;
	g->win = 0;
}

int	main(int c, char **v)
{
	t_general	*g;

	g = malloc(sizeof(t_general));
	alloc_g(g, c, v);
	if (check_error(g->v, g->i) == 1)
	{
		if (g != 0)
			free(g);
		exit(1);
	}
	start_cube(g);
}
