/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:59:04 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_strcmp(char *s, char *s2)
{
	int	i;

	i = 0;
	while (s[i] == s2[i] && s[i] && s2[i])
		i++;
	if (s[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}
