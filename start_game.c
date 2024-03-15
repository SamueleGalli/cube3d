/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/15 13:05:33 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	alloc_map(t_general g, int i)
{
	int	j;

	j = 0;
	g.l = NULL;
	while (j < i)
	{
		g.l = get_next_line(g.fd);
		g.cubed[j] = (char *)malloc(sizeof(char) * (ft_strlen(g.l) + 1));
		g.cubed[j] = ft_strdup(g.l);
		printf("\ncube = %s\n", g.cubed[j]);
		free(g.l);
		j++;
	}
	g.cubed[j] = NULL;
}

void	getting_line(t_general g, int i)
{
	g.l = get_next_line(g.fd);
	free(g.l);
	i++;
	while (g.l != 0)
	{
		g.l = get_next_line(g.fd);
		free(g.l);
		i++;
	}
	g.cubed = (char **)malloc(sizeof(char **) * i);
	alloc_map(g, i);
}

void	init_game(t_general g)
{
	g.fd = open(g.v[1], O_RDONLY);
	if (g.fd < 0)
	{
		printf("invalid map.cub try another\n");
		exit(0);
	}
	getting_line(g, 0);
}
