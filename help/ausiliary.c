/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ausiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:48 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/18 12:37:06 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	end_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
		i++;
	i--;
	return (i);
}

void	copy_cubed(t_general *g, int i, int j)
{
	g->tmp = (char **)malloc(sizeof(char *) * (end_mat(g->cubed) + 1));
	while (g->cubed[i] != 0)
	{
		g->tmp[i] = (char *)malloc(sizeof(char ) * (ft_strlen(g->cubed[i])));
		while (g->cubed[i][j] != 0)
		{
			g->tmp[i][j] = g->cubed[i][j];
			printf("g->tmp[i][j] = %c\n" ,g->tmp[i][j]);
			j++;
		}
		g->tmp[i][j] = 0;
		j = 0;
		i++;
	}
	g->tmp[i] = 0;
}

void	recopy(t_general *g, int i, int j)
{
	//free_mat()
	g->tmp = (char **)malloc(sizeof(char *) * (end_mat(g->cubed) + 1));
	while (g->cubed[i] != 0)
	{
		g->tmp[i] = (char *)malloc(sizeof(char ) * (ft_strlen(g->cubed[i])));
		while (g->cubed[i][j] != 0)
		{
			g->tmp[i][j] = g->cubed[i][j];
			printf("g->tmp[i][j] = %c\n" ,g->tmp[i][j]);
			j++;
		}
		g->tmp[i][j] = 0;
		j = 0;
		i++;
	}
	g->tmp[i] = 0;
}