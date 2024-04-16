/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ausiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:48 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/16 13:59:31 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

int	end_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
		i++;
	return (i);
}

void	copy_cubed(t_general *g)
{
	g->tmp = (char **)malloc(sizeof(char *) * (end_mat(g->cubed) + 2));
	g->x = -1;
	while (g->cubed[++g->x] != 0)
	{
		g->tmp[g->x] = (char *)malloc(sizeof(char) * \
		(ft_strlen(g->cubed[g->x]) + 1));
		while (g->cubed[g->x][g->y] != 0)
		{
			g->tmp[g->x][g->y] = g->cubed[g->x][g->y];
			g->y++;
		}
		g->tmp[g->x][g->y] = 0;
		g->y = 0;
	}
	g->tmp[g->x] = NULL;
	g->x = 0;
	g->y = 0;
}

void	recopy(t_general *g)
{
	if (g->cubed != 0)
		free_matrix(g->cubed);
	g->cubed = (char **)malloc(sizeof(char *) * (end_mat(g->tmp) + 1));
	while (g->tmp[g->x] != 0)
	{
		g->cubed[g->x] = (char *)malloc(sizeof(char) * \
		(ft_strlen(g->tmp[g->x]) + 1));
		while (g->tmp[g->x][g->y] != 0)
		{
			g->cubed[g->x][g->y] = g->tmp[g->x][g->y];
			g->y++;
		}
		g->cubed[g->x][g->y] = 0;
		g->y = 0;
		g->x++;
	}
	g->cubed[g->x] = 0;
	g->x = 0;
	g->y = 0;
}
