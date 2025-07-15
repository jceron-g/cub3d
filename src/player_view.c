/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:22:42 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:28:39 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_player_view(t_cube *cube)
{
	if (cube->player->player_view == 'N')
	{
		cube->player->dir_x = 0.0;
		cube->player->dir_y = -1.0;
		cube->player->plane_x = 0.66;
		cube->player->plane_y = 0.0;
	}
	else if (cube->player->player_view == 'S')
	{
		cube->player->dir_x = 0.0;
		cube->player->dir_y = 1.0;
		cube->player->plane_x = -0.66;
		cube->player->plane_y = 0.0;
	}
	set_player_view_side(cube);
}

void	set_player_view_side(t_cube *cube)
{
	if (cube->player->player_view == 'E')
	{
		cube->player->dir_x = 1.0;
		cube->player->dir_y = 0.0;
		cube->player->plane_x = 0.0;
		cube->player->plane_y = 0.66;
	}
	else if (cube->player->player_view == 'W')
	{
		cube->player->dir_x = -1.0;
		cube->player->dir_y = 0.0;
		cube->player->plane_x = 0.0;
		cube->player->plane_y = -0.66;
	}
}
