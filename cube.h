/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:17:58 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/08 13:45:56 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "minilibx_opengl/mlx.h"
# include <stdio.h>
# include <stdlib.h>

char	*ft_substr(char *s, int start, int len);

int		ft_strcmp(char *s, char *s2);
int		check_error(char **v, int i);
int		ft_strlcpy(char *dest, char *src, int size);
int		ft_strlen(char *s);

#endif