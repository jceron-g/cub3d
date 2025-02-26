/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:06 by jceron-g          #+#    #+#             */
/*   Updated: 2025/02/26 16:33:53 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"

typedef struct s_config
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color;
	char	*ceiling_color;
	char	**map;
	char	**file; //Me guardo el archivo .cub porque va a ser mas facil de trabajar con esto despues.
}	t_config;

void 	check_extension(char *str);
void	read_map_file(char *filename, t_config *config);
void	free_config(t_config *config);

#endif