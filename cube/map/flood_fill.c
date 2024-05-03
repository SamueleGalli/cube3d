/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:38:06 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/03 12:46:43 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	flood_fill(t_general *g, int j, int i)
{
	i = 0;
	if (j == 0 || j == g->y_end - 1)
	{
		while (g->cubed[j][i] != 0)
		{
			if (g->cubed[j][i] == '0' && i > 0 && i < g->x_end - 1)
				return (0);
			i++;
		}
	}
	else
	{
		if (g->cubed[j][ft_strlen(g->cubed[j]) - 1] == '0' || \
		g->cubed[j][0] == '0')
			return (0);
		return (1);
	}
	return (1);
}

int	is_valid(t_general *g)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (g->cubed[j] != 0)
	{
		if (flood_fill(g, j, i) == 0)
			return (0);
		j++;
	}
	return (1);
}
