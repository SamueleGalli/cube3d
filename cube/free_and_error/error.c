/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:53:03 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/06 18:15:43 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	cont_error_check(int i, int j, char **v)
{
	char	*sub;

	sub = ft_substr(v[i], j, ft_strlen(v[i]));
	if (ft_strcmp(sub, "cub") == 1)
	{
		free(sub);
		return (0);
	}
	free(sub);
	printf("Error\n(invalid extension)\n");
	return (1);
}

int	input_check(int n)
{
	if (n > 2)
	{
		printf("Error\n(too many arguments)");
		return (1);
	}
	else if (n == 1)
	{
		printf("Error\n(no arguments)\n");
		return (1);
	}
	return (0);
}

int	check_error(char **v, int i)
{
	int	j;
	int	n;

	n = i;
	i = 1;
	j = 0;
	if (input_check(n) == 1)
		return (1);
	while (v[i][j] && v[i][j] != '.')
		j++;
	if (v[i][j] != 0 && v[i][j] == '.' && v[i][j + 1] != 0)
		j++;
	else
	{
		printf("Error\n(invalid syntax)\n");
		return (1);
	}
	if (cont_error_check(i, j, v) == 1)
		return (1);
	return (0);
}

int	cont_map_error(t_general *g)
{
	if (g->in == -1)
	{
		printf("Error\n(is not allowed newline in map)\n");
		end_program(g);
	}
	else if (g->in == -2)
	{
		printf("Error\n(is not allowed space in map)\n");
		end_program(g);
	}
	else if (is_valid(g) == 0)
	{
		printf("Error\n(map not closed by walls)");
		return (1);
	}
	return (0);
}

int	map_error(t_general *g)
{
	if (g->invalid_maxp > 1)
	{
		printf("Error\n(too many players)\n");
		return (1);
	}
	else if (g->invalid_sign > 0)
	{
		printf("Error\n(invalid sign)\n");
		return (1);
	}
	else if (g->p_view == 0)
	{
		printf("Error\n(missing or invalid player)\n");
		return (1);
	}
	else
		return (cont_map_error(g));
}
