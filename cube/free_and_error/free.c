/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:42:24 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	free_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	end_program(t_general *g)
{
	if (g->l != NULL)
		free(g->l);
	if (g->cubed != 0)
		free_matrix(g->cubed);
	if (g->tmp != 0)
		free_matrix(g->tmp);
	if (g->mlx != 0 && g->win != 0)
	{
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
	}
	free(g->mlx);
	if (g != 0)
		free(g);
	exit(0);
}
