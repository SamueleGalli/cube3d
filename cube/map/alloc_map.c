/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:29:45 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/09 12:17:59 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

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

void	alloc_map(t_general *g, int i)
{
	int	j;

	j = 0;
	g->cubed = (char **)malloc(sizeof(char *) * i);
	while (j < i)
	{
		g->l = get_next_line(g->fd);
		if (g->l == 0)
			break ;
		g->cubed[j] = (char *)malloc(sizeof(char) * (ft_strlen(g->l) + 1));
		alloc_cube(g, j);
		free(g->l);
		j++;
	}
	g->cubed[j] = 0;
	g->x_end = (ft_strlen(g->cubed[0]) - 1);
	g->y_end = (ft_mat_len(g->cubed) - 1);
	if (g->x_end == -1 && g->y_end == -1)
	{
		printf("Error\n(map must be not empty)");
		end_program(g);
	}
}

int	getting_line(t_general *g, int i)
{
	g->l = get_next_line(g->fd);
	free(g->l);
	i++;
	while (g->l != 0)
	{
		g->l = get_next_line(g->fd);
		free(g->l);
		i++;
	}
	return (i);
}
