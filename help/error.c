/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:53:03 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/08 13:26:17 by sgalli           ###   ########.fr       */
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
	printf("invalid extension\n");
	return (1);
}

int	check_error(char **v, int i)
{
	int		j;

	i = 1;
	j = 0;
	if (v[i] == 0)
	{
		printf("no arguments\n");
		return (1);
	}
	while (v[i][j] && v[i][j] != '.')
		j++;
	if (v[i][j] != 0 && v[i][j] == '.' && v[i][j + 1] != 0)
		j++;
	else
	{
		printf("invalid syntax\n");
		return (1);
	}
	if (cont_error_check(i, j, v) == 1)
		return (1);
	return (0);
}
