/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:29:45 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/22 11:10:41 by sgalli           ###   ########.fr       */
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

void	check_max_p(t_general *g, int i)
{
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		if (g->l[i] == 'N' || g->l[i] == 'S' || g->l[i] == 'E' ||
			g->l[i] == 'W')
			g->invalid_maxp++;
		i++;
	}
}

void	check_invalid_char(t_general *g, int i)
{
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		if (g->l[i] != 'N' && g->l[i] != 'S' && g->l[i] != 'E' && \
		g->l[i] != 'W' && g->l[i] != '1' && g->l[i] != '0')
			g->invalid_sign++;
		i++;
	}
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
		check_max_p(g, 0);
		check_invalid_char(g, 0);
		alloc_cube(g, j);
		free(g->l);
		j++;
	}
	g->cubed[j] = 0;
	g->x_end = (ft_strlen(g->cubed[0]) - 1);
	g->y_end = (ft_mat_len(g->cubed) - 1);
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
