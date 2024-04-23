/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:42:24 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/23 11:08:28 by sgalli           ###   ########.fr       */
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

void	free_int(int **mat, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	end_program(t_general *g)
{
	if (g == 0)
		return (0);
	if (g->l != NULL)
		free(g->l);
	if (g->cubed != 0)
		free_matrix(g->cubed);
	if (g->tmp != 0)
		free_matrix(g->tmp);
	if (g->img != 0)
		mlx_destroy_image(g->mlx, g->img);
	if (g->mlx != 0 && g->win != 0)
	{
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
	}
	if (g->buf != 0)
		free_int(g->buf, g->height);
	if (g->texture != 0)
		free_int(g->texture, 6);
	free(g->mlx);
	free(g);
	exit(0);
}
