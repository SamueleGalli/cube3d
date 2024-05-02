/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:29:45 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/02 15:27:08 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	getting_line(t_general *g, int i)
{
	g->max_line = 0;
	g->max_len = 0;
	g->l = get_next_line(g->fd, g);
	while (g->l != 0)
	{
		if (checking_1_0(g) == 1)
			i++;
		g->max_line++;
		free(g->l);
		g->l = get_next_line(g->fd, g);
	}
	return (i);
}

void	alloc_cube(t_general *g, int j)
{
	int	i;

	i = 0;
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		g->cubed[j][i] = g->l[i];
		i++;
	}
	g->cubed[j][i] = '\0';
}

void	while_map(t_general *g, int max)
{
	if (g->l != 0 && g->l[g->i_cube] != '\n' && g->l[g->i_cube] != '\0' && \
	(g->l[g->i_cube] == '1' || g->l[g->i_cube] == '0'))
		mapping(g, max);
	else
	{
		if (g->in > 0)
			g->in++;
		cont_alloc_map(g, g->i_cube);
	}
}

int	shorter(t_general *g, int j, int i)
{
	g->l = get_next_line(g->fd, g);
	if (g->l[g->i_cube] != '\n' && g->l[g->i_cube] != '\0')
	{
		while (g->l[g->i_cube] != '\0' && g->l[g->i_cube] != '\n' \
		&& g->l[g->i_cube] == ' ')
			g->i_cube++;
		while_map(g, i);
		if (i > 0 && g->i == i)
			g->cubed[g->i] = NULL;
	}
	j++;
	if (g->in > 1)
		g->in++;
	if (g->in > 0 && g->in < i)
		new_line_or_space(g);
	free(g->l);
	g->l = 0;
	g->i_cube = 0;
	return (j);
}

void	alloc_map(t_general *g, int i)
{
	int	j;

	j = 0;
	g->i = 0;
	g->i_cube = 0;
	g->size_mat = 0;
	while (j < g->max_line)
		j = shorter(g, j, i);
	map_validity(g);
	g->x_end = (ft_strlen(g->cubed[0]) - 1);
	g->y_end = (ft_mat_len(g->cubed) - 1);
}
