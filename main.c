/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:23 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/11 19:02:21 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int i, char **v)
{
	t_general	g;

	g.i = i;
	g.v = v;
	if (check_error(g.v, g.i) == 1)
		exit(1);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 800, 600, "test finestra");
	mlx_loop(g.mlx);
}
