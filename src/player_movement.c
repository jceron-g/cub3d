/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:05:14 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:17:09 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_wall(t_cube *cube, double x, double y)
{
	int	mx;
	int	my;

	mx = x;
	my = y;
	if (cube->config->map[my][mx] == '1')
		return (1);
	return (0);
}

int	move_forward(t_cube *cube)
{
	t_player	*player;
	double		new_x;
	double		new_y;

	player = cube->player;
	new_x = player->pos_x + player->dir_x * MOVE_SPEED;
	new_y = player->pos_y + player->dir_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return (0);
}

int	move_backward(t_cube *cube)
{
	t_player	*player;
	double		new_x;
	double		new_y;

	player = cube->player;
	new_x = player->pos_x - player->dir_x * MOVE_SPEED;
	new_y = player->pos_y - player->dir_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return (0);
}

int	move_left(t_cube *cube)
{
	t_player	*player;
	double		new_x;
	double		new_y;

	player = cube->player;
	new_x = player->pos_x - player->plane_x * MOVE_SPEED;
	new_y = player->pos_y - player->plane_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return (0);
}

int	move_right(t_cube *cube)
{
	t_player	*player;
	double		new_x;
	double		new_y;

	player = cube->player;
	new_x = player->pos_x + player->plane_x * MOVE_SPEED;
	new_y = player->pos_y + player->plane_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return (0);
}
