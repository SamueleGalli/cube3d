/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:29:45 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/19 16:16:13 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	alloc_cube(t_general *g, int j)
{
	int	i;

	i = 0;
	while (g->l[i] != '\0')
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
