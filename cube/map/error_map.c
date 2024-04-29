/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:56 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/29 11:06:41 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_max_p(t_general *g, int i)
{
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		if (g->l[i] == 'N' || g->l[i] == 'S' || g->l[i] == 'E' || \
			g->l[i] == 'W')
			g->invalid_maxp++;
		i++;
	}
}

void	check_invalid_char(t_general *g, int i)
{
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		if (g->l[i] != 'N' && g->l[i] != 'S' && g->l[i] != 'E' && \
		g->l[i] != 'W' && g->l[i] != '1' && g->l[i] != '0' && \
		g->l[i] != ' ')
			g->invalid_sign++;
		i++;
	}
}
