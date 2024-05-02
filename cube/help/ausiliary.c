/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ausiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:48 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/02 12:03:42 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	end_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
		i++;
	return (i);
}

void	cont_copy_cubed(t_general *g)
{
	g->y = 0;
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

void	copy_cubed(t_general *g)
{
	if (g->tmp != 0)
		free_matrix(g->tmp);
	g->tmp = (char **)malloc(sizeof(char *) * (end_mat(g->cubed) + 2));
	g->x = 0;
	while (g->cubed[g->x] != 0)
	{
		cont_copy_cubed(g);
		g->x++;
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

void	escape_space(t_general *g)
{
	while (g->l[g->i_fc] != '\0' && g->l[g->i_fc] != '\n' && \
	g->l[g->i_fc] == ' ')
		g->i_fc++;
}
