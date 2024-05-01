/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:29:45 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/01 18:44:09 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	getting_line(t_general *g, int i)
{
	g->max_line = 0;
	g->l = get_next_line(g->fd, g);
	while (g->l != 0)
	{
		if (g->l != 0 && g->l[0] != 0 && g->l[0] != '\n' && g->l[0] != 'F'
			&& g->l[0] != 'C' && g->l[0] != 'E' && g->l[0] != 'N'
			&& g->l[0] != 'S' && g->l[0] != 'W')
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

void	cont_alloc_map(t_general *g)
{
	if (g->l != 0 && g->l[0] == 'F' && g->l[1] == ' ' && g->check_t == 4)
		flooring(g);
	else if (g->l != 0 && g->l[0] == 'C' && g->l[1] == ' ' && g->check_t == 4)
		ceiling(g);
	else if (g->l != 0 && g->l[0] == 'E' && g->l[1] == 'A' \
	&& g->l[2] == ' ')
		east(g);
	else if (g->l != 0 && g->l[0] == 'N' && g->l[1] == 'O' \
	&& g->l[2] == ' ')
		north(g);
	else if (g->l != 0 && g->l[0] == 'S' && g->l[1] == 'O' \
	&& g->l[2] == ' ')
		south(g);
	else if (g->l != 0 && g->l[0] == 'W' && g->l[1] == 'E' \
	&& g->l[2] == ' ')
		west(g);
	else
	{
		printf("Error\n(texture or color with invalid alias)\n");
		printf("Try somthing like (WE) (EA) (SO) (NO) or (F) (C) \n");
		end_program(g);
	}
}

int	while_map(t_general *g, int i, int max)
{
	if (g->l[0] == '\n')
		return (++i);
	else if ((g->l != 0 && g->l[0] != '\n' && g->check_fc == 2 \
	&& g->check_t == 4) && (g->l[0] == '1' \
	|| g->l[0] == '0' || g->l[0] == ' ' || g->l[0] == '\t'))
	{
		if (g->cubed == 0)
			g->cubed = (char **)malloc(sizeof(char *) \
			* (max + 1));
		if (g->size_mat < ft_strlen(g->l) + 1)
			g->size_mat = ft_strlen(g->l) + 1;
		g->cubed[g->i] = (char *)malloc(sizeof(char) * (ft_strlen(g->l) + 1));
		check_max_p(g, 0);
		check_invalid_char(g, 0);
		alloc_cube(g, g->i);
		g->i++;
	}
	else
		cont_alloc_map(g);
	i++;
	return (i);
}

void	alloc_map(t_general *g, int i)
{
	int	i2;

	i2 = 0;
	g->i = 0;
	g->size_mat = 0;
	while (i2 < g->max_line)
	{
		g->l = get_next_line(g->fd, g);
		i2 = while_map(g, i2, i);
		free(g->l);
		g->l = 0;
	}
	map_validity(g);
	g->cubed[g->i] = NULL;
	g->x_end = (ft_strlen(g->cubed[0]) - 1);
	g->y_end = (ft_mat_len(g->cubed) - 1);
}
