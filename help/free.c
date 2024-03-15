/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:42:24 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/15 14:41:28 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	free_matrix(t_general *g)
{
	int	i;

	i = 0;
	while (g->cubed[i] != 0)
	{
		free(g->cubed[i]);
		i++;
	}
	free(g->cubed);
}

int	end_program(t_general *g)
{
	if (g->l != NULL)
		free(g->l);
	if (g->cubed != 0)
		free_matrix(g);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	if (g != 0)
		free(g);
	exit(0);
}
