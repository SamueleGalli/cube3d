/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:16:46 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/02 12:52:12 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	east(t_general *g)
{
	int	k;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g->east != 0)
	{
		printf("Error\n(too many East)\n");
		end_program(g);
	}
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != '.')
		i++;
	k = i;
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		j++;
		i++;
	}
	g->east = (char *)malloc(sizeof(char) * (j + 1));
	i = k;
	j = 0;
	while (g->l[i] != '\0' && g->l[i] != '\n')
		g->east[j++] = g->l[i++];
	g->east[j] = '\0';
}

void	north(t_general *g)
{
	int	k;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g->north != 0)
	{
		printf("Error\n(too many North)\n");
		end_program(g);
	}
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != '.')
		i++;
	k = i;
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		j++;
		i++;
	}
	g->north = (char *)malloc(sizeof(char) * (j + 1));
	i = k;
	j = 0;
	while (g->l[i] != '\0' && g->l[i] != '\n')
		g->north[j++] = g->l[i++];
	g->north[j] = '\0';
}

void	south(t_general *g)
{
	int	k;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g->south != 0)
	{
		printf("Error\n(too many South)\n");
		end_program(g);
	}
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != '.')
		i++;
	k = i;
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		j++;
		i++;
	}
	g->south = (char *)malloc(sizeof(char) * (j + 1));
	i = k;
	j = 0;
	while (g->l[i] != '\0' && g->l[i] != '\n')
		g->south[j++] = g->l[i++];
	g->south[j] = '\0';
}

void	west(t_general *g)
{
	int	k;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g->west != 0)
	{
		printf("Error\n(too many West)\n");
		end_program(g);
	}
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != '.')
		i++;
	k = i;
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		j++;
		i++;
	}
	g->west = (char *)malloc(sizeof(char) * (j + 1));
	i = k;
	j = 0;
	while (g->l[i] != '\0' && g->l[i] != '\n')
		g->west[j++] = g->l[i++];
	g->west[j] = '\0';
}
