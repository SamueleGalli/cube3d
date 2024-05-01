/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:46:02 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/01 18:08:53 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_invalid_number(t_general *g)
{
	if (ft_atoi(g->floor[0]) > 255 || ft_atoi(g->floor[1]) > 255 || \
	ft_atoi(g->floor[2]) > 255 || ft_atoi(g->sky[0]) > 255 \
	|| ft_atoi(g->sky[1]) > 255 || ft_atoi(g->sky[2]) > 255)
	{
		printf("Error\n(RGB color to large)\n");
		end_program(g);
	}
	else if (ft_atoi(g->floor[0]) < 0 || ft_atoi(g->floor[1]) < 0 || \
	ft_atoi(g->floor[2]) < 0 || ft_atoi(g->sky[0]) < 0 \
	|| ft_atoi(g->sky[1]) < 0 || ft_atoi(g->sky[2]) < 0)
	{
		printf("Error\n(RGB color to small)\n");
		end_program(g);
	}
}

void	invalid_color(t_general *g)
{
	if (g->floor != 0 && g->sky != 0)
	{
		if (g->floor[0] != 0 && g->floor[1] != 0 && \
		g->floor[2] != 0 && g->sky[0] != 0 && g->sky[1] != 0 \
		&& g->sky[2] != 0)
			check_invalid_number(g);
		else
		{
			printf("Error\n(invalid color)\n");
			end_program(g);
		}
	}
}

void	map_validity(t_general *g)
{
	if (g->check_fc != 2 || g->check_t != 4)
	{
		if (g->check_t > 0)
			printf("Error\n(missing texture/s)\n");
		else if (g->east == 0 && g->south == 0 && g->west == 0 && g->north == 0)
			printf("Error\n(no texture found)\n");
		else
		{
			printf("Error\n(invalid corpe map indentation)\n");
			printf("The correct one should be:\n");
			printf("1)Texture\n2)(C or F) R,G,B\n3)The map");
		}
		end_program(g);
	}
	if (g->cubed == 0)
	{
		printf("Error\n(map must be not empty)");
		end_program(g);
	}
}
