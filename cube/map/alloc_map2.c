/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:42:06 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/03 14:36:10 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	last_control(t_general *g)
{
	if (g->sky == 0 && g->floor == 0 && g->west == 0 && g->east == 0 \
	&& g->north == 0 && g->south == 0 && g->cubed == 0)
	{
		printf("Error\n(find nothing usefull in file)\n");
		end_program(g);
	}
	else
	{
		printf("Error\n(texture or color with invalid alias)\n");
		printf("Try somthing like (WE) (EA) (SO) (NO) or (F) (C) \n");
		end_program(g);
	}
}

void	cont_alloc_map(t_general *g, int i)
{
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] == ' ')
		i++;
	if (g->l[i] == '\0' || g->l[i] == '\n')
		return ;
	if (g->l != 0 && g->l[i] == 'F' && g->l[i + 1] == ' ')
		flooring(g);
	else if (g->l != 0 && g->l[i] == 'C' && g->l[i + 1] == ' ')
		ceiling(g);
	else if (g->l != 0 && g->l[i] == 'E' && g->l[i + 1] == 'A' \
	&& g->l[i + 2] == ' ')
		east(g);
	else if (g->l != 0 && g->l[i] == 'N' && g->l[i + 1] == 'O' \
	&& g->l[i + 2] == ' ')
		north(g);
	else if (g->l != 0 && g->l[i] == 'S' && g->l[i + 1] == 'O' \
	&& g->l[i + 2] == ' ')
		south(g);
	else if (g->l != 0 && g->l[i] == 'W' && g->l[i + 1] == 'E' \
	&& g->l[i + 2] == ' ')
		west(g);
	else
		last_control(g);
}

int	check_newline(char *l)
{
	int	i;

	i = 0;
	while (l[i] != '\0')
	{
		if (l[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	mapping(t_general *g, int max)
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
	if (g->i == max && check_newline(g->l) == 1 && (g->check_fc != 2 || \
	g->east == 0 || g->south == 0 || g->west == 0 || g->north == 0))
	{
		g->cubed[g->i] = NULL;
		printf("Error\n(invalid corpe detected:");
		printf("map must be at the end)\n");
		end_program(g);
	}
	if (g->in == 0)
		g->in++;
}

void	new_line_or_space(t_general *g)
{
	int	i;

	i = 0;
	if (g->l != 0 && g->l[i] == '\n')
		g->in = -1;
	else if (g->l != 0 && g->l[i] == ' ')
	{
		while (g->l[i] != '\0' && g->l[i] == ' ')
			i++;
		if (g->l[i] == '\n')
			g->in = -2;
	}
}
