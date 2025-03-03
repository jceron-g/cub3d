/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:06 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/03 11:28:09 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_rgb;
	char	*c_rgb;
	char	**map;
	char	**file;
	int		data_saved;
}	t_config;

void 	check_extension(char *str);
void	read_map_file(char *filename, t_config *config);
void	free_config(t_config *config);
char 	*space_skip_save(char *str);
void	save_data(t_config *config);
void	save_routes(char **coord, char *route, t_config *config);

#endif