/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:23 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/18 12:22:24 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	start_cube(t_general *g)
{
	init_game(g);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 800, 600, "cube3D");
	mlx_hook(g->win, 17, 1L << 17, end_program, g);
	mlx_key_hook(g->win, manage_key, g);
	mlx_loop(g->mlx);
}

int	main(int i, char **v)
{
	t_general	*g;

	g = malloc(sizeof(t_general));
	g->i = i;
	g->v = v;
	g->l = NULL;
	g->tmp = NULL;
	g->cubed = NULL;
	if (check_error(g->v, g->i) == 1)
	{
		if (g != 0)
			free(g);
		exit(1);
	}
	start_cube(g);
}
