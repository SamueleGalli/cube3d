/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:22:38 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/10 15:47:30 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

/*
A = 97
B = 100
W = 119
S = 115
<- = 65361
-> = 65363
*/

/*void	render(t_general *g)
{
	g->x = 0;
	g->y = 0;
	while (g->cubed[g->y] != 0)
	{
		while (g->cubed[g->y][g->x] != 0)
		{
			printf("%c", g->cubed[g->y][g->x]);
			g->x++;
		}
		printf("\n");
		g->x = 0;
		g->y++;
	}
	g->y = 0;
	g->x = 0;
}*/

void	move_direction(char c, t_general *g)
{
	if (c == 'S' && g->cubed[g->y_p + 1][g->x_p] != '1')
	{
		g->y_p++;
		g->cubed[g->y_p][g->x_p] = g->p_view;
		g->cubed[g->y_p - 1][g->x_p] = '0';
	}
	else if (c == 'W' && g->cubed[g->y_p - 1][g->x_p] != '1')
	{
		g->y_p--;
		g->cubed[g->y_p][g->x_p] = g->p_view;
		g->cubed[g->y_p + 1][g->x_p] = '0';
	}
	else if (c == 'A' && g->cubed[g->y_p][g->x_p - 1] != '1')
	{
		g->x_p--;
		g->cubed[g->y_p][g->x_p] = g->p_view;
		g->cubed[g->y_p][g->x_p + 1] = '0';
	}
	else if (c == 'D' && g->cubed[g->y_p][g->x_p + 1] != '1')
	{
		g->x_p++;
		g->cubed[g->y_p][g->x_p] = g->p_view;
		g->cubed[g->y_p][g->x_p - 1] = '0';
	}
}

int	manage_key(int key, t_general *g)
{
	if (key == 65307)
		end_program(g);
	if (key == 97)
		move_direction('A', g);
	else if (key == 119)
		move_direction('W', g);
	else if (key == 100)
		move_direction('D', g);
	else if (key == 115)
		move_direction('S', g);
	//else if (key == 65361 || key == 65363)
		//rotate(g, key);
	return (1);
}
