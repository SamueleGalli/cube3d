/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:30:30 by sgalli            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/09 15:09:09 by sgalli           ###   ########.fr       */
=======
/*   Updated: 2024/04/09 12:20:50 by sgalli           ###   ########.fr       */
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	init_check(int i, int j, t_general *g)
{
<<<<<<< HEAD
	if (g->cubed[j + 1][i] != 0 && g->cubed[j + 1][i] == '0' && \
	j + 1 < g->y_end)
=======
	if (g->cubed[j + 1][i] != 0 && g->cubed[j + 1][i] == '0' &&
		j + 1 < g->y_end)
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
	{
		g->cubed[j + 1][i] = '1';
		init_check(i, j + 1, g);
	}
<<<<<<< HEAD
	if (g->cubed[j - 1][i] != 0 && g->cubed[j - 1][i] == '0' && \
	j - 1 > 0)
=======
	if (g->cubed[j - 1][i] != 0 && g->cubed[j - 1][i] == '0' &&
		j - 1 > 0)
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
	{
		g->cubed[j - 1][i] = '1';
		init_check(i, j - 1, g);
	}
<<<<<<< HEAD
	if (g->cubed[j][i + 1] != 0 && g->cubed[j][i + 1] == '0' && \
	i + 1 < g->x_end)
=======
	if (g->cubed[j][i + 1] != 0 && g->cubed[j][i + 1] == '0' && 
		i + 1 < g->x_end)
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
	{
		g->cubed[j][i + 1] = '1';
		init_check(i + 1, j, g);
	}
<<<<<<< HEAD
	if (g->cubed[j][i - 1] != 0 && g->cubed[j][i - 1] == '0' && \
	i - 1 > 0)
=======
	if (g->cubed[j][i - 1] != 0 && g->cubed[j][i - 1] == '0' &&
		i - 1 > 0)
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
	{
		g->cubed[j][i - 1] = '1';
		init_check(i - 1, j, g);
	}
}

int	check_angle(int i, int j, t_general *g)
{
	if (j == g->x_end && i == g->y_end && g->cubed[i][j - 1] == '1' && \
	g->cubed[i - 1][i] == '1')
		return (0);
	else if (j == g->x_end && i == 0 && g->cubed[i][j - 1] == '1' && \
	g->cubed[i + 1][i] == '1')
		return (0);
	else if (j == 0 && i == 0 && g->cubed[i][j + 1] == '1' && \
	g->cubed[i + 1][i] == '1')
		return (0);
	else if (j == 0 && i == g->y_end && g->cubed[i][j + 1] == '1' && \
	g->cubed[i - 1][i] == '1')
		return (0);
	return (1);
}

int	last_check(t_general *g, int i, int j)
{
	while (g->cubed[i] != 0)
	{
		while (g->cubed[i][j] != 0)
		{
			if (g->cubed[i][j] == '0')
			{
<<<<<<< HEAD
				if ((j == g->x_end && i == g->y_end) || (j == g->x_end \
				&& i == 0) || (j == 0 && i == 0) || (j == 0 && i == g->y_end))
=======
				if ((j == g->x_end && i == g->y_end) || (j == g->x_end && i == 0) || \
				(j == 0 && i == 0) || (j == 0 && i == g->y_end))
>>>>>>> 6d26ea0b2dd8bd80e53dceb146ed3a81aa8d14f7
				{
					if (check_angle(i, j, g) == 1)
						return (0);
				}
				else
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_valid(t_general *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	copy_cubed(g);
	while (g->cubed[j] != 0)
	{
		while (g->cubed[j][i] != 0)
		{
			if (g->cubed[j][i] == 'N' || g->cubed[j][i] == 'S'
				|| g->cubed[j][i] == 'W' || g->cubed[j][i] == 'E')
			{
				g->cubed[j][i] = '1';
				init_check(i, j, g);
				return (last_check(g, 0, 0));
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
