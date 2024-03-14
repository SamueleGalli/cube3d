/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/14 11:09:42 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	getting_line(t_general g, int i, char *line)
{
	int	j;

	j = 0;
	line = get_next_line(g.fd);
	if (line == NULL)
	{
		free(line);
		exit(0);
	}
	while (line[j] != 0)
	{
		j++;
		if (line[j] == '\n')
			i++;
	}
	i++;
}

void	init_game(t_general g)
{
	g.fd = open(g.v[1], O_RDONLY);
	if (g.fd < 0)
	{
		printf("invalid map.cub try another\n");
		exit(0);
	}
	getting_line(g, 0, NULL);
}
