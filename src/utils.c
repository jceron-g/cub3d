/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:47:37 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/01 20:23:01 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*space_skip_save(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (ft_strdup(str + i));
}

void	save_routes(char **coord, char *route, t_config *config)
{
	if (!*coord)
		*coord = route;
	config->data_saved++;
}

int	check_data(t_config *config)
{
	if (!config->no)
		return (0);
	else if (!config->so)
		return (0);
	else if (!config->ea)
		return (0);
	else if (!config->we)
		return (0);
	else if (!config->c_rgb)
		return (0);
	else if (!config->f_rgb)
		return (0);
	return (1);
}

void	set_player_view(t_cube *cube)
{
	if(cube->player->player_view == 'N')
	{
		cube->player->dir_x = 0.0;
		cube->player->dir_y = -1.0;
		cube->player->plane_x = 0.66;  // 90° a la derecha de Norte = Este
		cube->player->plane_y = 0.0;
	}
	else if(cube->player->player_view == 'S')
	{
		cube->player->dir_x = 0.0;
		cube->player->dir_y = 1.0;
		cube->player->plane_x = -0.66;  // 90° a la derecha de Sur = Oeste
		cube->player->plane_y = 0.0;
	}
	else if(cube->player->player_view == 'E')
	{
		cube->player->dir_x = 1.0;
		cube->player->dir_y = 0.0;
		cube->player->plane_x = 0.0;
		cube->player->plane_y = 0.66;  // 90° a la derecha de Este = Sur
	}
	else if (cube->player->player_view == 'W')
	{
		cube->player->dir_x = -1.0;
		cube->player->dir_y = 0.0;
		cube->player->plane_x = 0.0;
		cube->player->plane_y = -0.66;  // 90° a la derecha de Oeste = Norte
	}
}