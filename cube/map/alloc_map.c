/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:29:45 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/24 15:16:32 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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

void	cont_alloc_map(t_general *g)
{
	if (g->l[0] == 'F')
		flooring(g);
	else if (g->l[0] == 'C')
		ceiling(g);
	else if (g->l[0] == 'E' || g->l[0] == 'N' || g->l[0] == 'S' || \
	g->l[0] == 'W')
		coordinate(g);
}

int	while_map(t_general *g, int j)
{
	if (g->l[0] != 'F' && g->l[0] != 'C' && g->l[0] != 'E' && \
		g->l[0] != 'N' && g->l[0] != 'S' && g->l[0] != 'W')
	{
		g->cubed[j] = (char *)malloc(sizeof(char) * (ft_strlen(g->l) + 1));
		check_max_p(g, 0);
		check_invalid_char(g, 0);
		alloc_cube(g, j);
		j++;
	}
	else
		cont_alloc_map(g);
	return (j);
}

void	alloc_map(t_general *g, int i)
{
	int	j;

	j = 0;
	g->cubed = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < i)
	{
		g->l = get_next_line(g->fd);
		j = while_map(g, j);
		free(g->l);
	}
	g->cubed[j] = NULL;
	g->x_end = (ft_strlen(g->cubed[0]) - 1);
	g->y_end = (ft_mat_len(g->cubed) - 1);
}
