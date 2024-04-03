/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:22:38 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/03 17:28:52 by sgalli           ###   ########.fr       */
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

int	manage_key(int key, t_general *g)
{
	if (key == 65307)
		end_program(g);
	if (key == 97)
		printf("A premuta\n");
	else if (key == 119)
		printf("W premuta\n");
	else if (key == 100)
		printf("D premuta\n");
	else if (key == 115)
		printf("S premuta\n");
	else if (key == 65361)
		printf("<- premuta\n");
	else if (key == 65363)
		printf("-> premuta\n");
	return (1);
}
