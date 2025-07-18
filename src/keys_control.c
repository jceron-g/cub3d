/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:55:17 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:04:23 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press_control(mlx_key_data_t keydata, t_cube *cube)
{
	t_player	*player;

	player = cube->player;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		player->rotate = -1;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		player->rotate = 1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player->move_y = 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player->move_x = -1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player->move_y = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player->move_x = 1;
	return (0);
}

int	key_release_control(mlx_key_data_t keydata, t_cube *cube)
{
	t_player	*player;

	player = cube->player;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		player->move_y = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		player->move_y = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		player->move_x = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		player->move_x = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		player->rotate = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		player->rotate = 0;
	return (0);
}
