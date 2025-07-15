/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:03:40 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:04:05 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_in_direction(t_cube *cube, double rot_speed)
{
	t_player	*player;
	double		aux_x;

	player = cube->player;
	aux_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y
		* sin(rot_speed);
	player->dir_y = aux_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	aux_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y
		* sin(rot_speed);
	player->plane_y = aux_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

void	rotate_player(t_cube *cube, double rotation_dir)
{
	double	rot_speed;

	rot_speed = ROTATION_SPEED * rotation_dir;
	rotate_in_direction(cube, rot_speed);
}
