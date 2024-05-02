/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ausiliary2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:24:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/02 15:25:11 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	other_color(t_general *g, int t)
{
	int	i;

	i = g->i_fc;
	if (g->j == 3)
	{
		while (g->l[i] != 0)
		{
			if (g->l[i] != 0 && g->l[i] != ' ' && g->l[i] == ',')
			{
				if (t == 1)
					g->sky[g->j] = 0;
				else if (t == 2)
					g->floor[g->j] = 0;
				printf("Error\n(too many colors)");
				printf("only RGB format is supported\n");
				end_program(g);
			}
			i++;
		}
	}
}

int	checking_1_0(t_general *g)
{
	int	i;

	if (g->l != 0 && g->l[0] != 0 && g->l[0] != '\n')
	{
		i = 0;
		while ((g->l[i] == ' ' || g->l[i] == '\t') && g->l[i] != '\0' \
		&& g->l[i] != '1' && g->l[i] != '0')
			i++;
		if (g->l[i] != '\0' && (g->l[i] == '1' || g->l[i] == '0'))
		{
			if (ft_strlen(g->l) > g->max_len)
				g->max_len = ft_strlen(g->l);
			return (1);
		}
	}
	return (0);
}
