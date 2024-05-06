/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:04:46 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/06 17:56:37 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_f(t_general *g, int j, int i)
{
	if (j == 0)
	{
		if (g->cubed[j + 1][i] == '0')
			return (0);
		return (1);
	}
	else
	{
		if (g->cubed[j - 1][i] == '0')
			return (0);
		return (1);
	}
}
