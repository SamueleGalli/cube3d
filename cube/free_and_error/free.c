/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:42:24 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/29 12:23:54 by sgalli           ###   ########.fr       */
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
	if (mat == 0)
		return ;
	while (i < max)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	cont_free(t_general *g)
{
	if (g->buf != 0)
		free_int(g->buf, g->height);
	if (g->texture != 0)
		free_int(g->texture, g->i_texture);
	if (g->east != 0)
		free(g->east);
	if (g->west != 0)
		free(g->west);
	if (g->north != 0)
		free(g->north);
	if (g->south != 0)
		free(g->south);
	if (g->floor != 0)
		free_matrix(g->floor);
	if (g->sky != 0)
		free_matrix(g->sky);
	if (g->save != 0)
		free(g->save);
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
	else if (g->mlx != 0)
		mlx_destroy_display(g->mlx);
	cont_free(g);
	free(g->mlx);
	free(g);
	exit(0);
}
