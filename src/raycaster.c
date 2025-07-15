/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:13:00 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:13:49 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	did_it_hit(t_ray *ray, t_config *config)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (config->map[ray->map_y][ray->map_x] == '1'
			|| config->map[ray->map_y][ray->map_x] == '\n'
			|| config->map[ray->map_y][ray->map_x] == '\0'
			|| config->map[ray->map_y][ray->map_x] == ' ')
			hit = 1;
	}
}

void	ray_steps(t_ray *ray, t_player *player)
{
	if (ray->cos < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->sin < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
}

void	ft_dda(t_ray *ray, t_cube *cube, int i)
{
	double	distance_corrected;

	(void)i;
	ray->map_x = (int)cube->player->pos_x;
	ray->map_y = (int)cube->player->pos_y;
	ray->delta_x = fabs(1 / ray->cos);
	ray->delta_y = fabs(1 / ray->sin);
	ray_steps(ray, cube->player);
	did_it_hit(ray, cube->config);
	if (ray->side == 0)
		ray->distance = (ray->map_x - cube->player->pos_x + (1 - ray->step_x)
				/ 2) / ray->cos;
	else
		ray->distance = (ray->map_y - cube->player->pos_y + (1 - ray->step_y)
				/ 2) / ray->sin;
	distance_corrected = ray->distance * cos(ray->angle
			- atan2(cube->player->dir_y, cube->player->dir_x));
	paint_wall(cube, ray, i, distance_corrected);
}

void	ft_raycaster(t_cube *cube)
{
	int		i;
	double	angle;
	double	start;
	double	player_angle;

	i = 0;
	angle = (FOV / WIDTH) * PI / 180;
	player_angle = atan2(cube->player->dir_y, cube->player->dir_x);
	start = player_angle - (angle * (WIDTH / 2));
	while (i < WIDTH)
	{
		cube->ray[i].angle = start + (angle * i);
		cube->ray[i].cos = cos(cube->ray[i].angle);
		cube->ray[i].sin = sin(cube->ray[i].angle);
		ft_dda(&cube->ray[i], cube, i);
		i++;
	}
}
