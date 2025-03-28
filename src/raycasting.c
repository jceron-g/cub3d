/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:52 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/28 13:48:32 by jceron-g         ###   ########.fr       */
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
		if (config->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/*step_x y step_y nos dicen en qué dirección movernos en cada iteración
del algoritmo DDA (raycasting). side_x y side_y nos dicen a qué distancia
está la primera pared en cada eje, lo que nos ayudará a decidir si el rayo
avanza en X o en Y en cada paso.*/
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
	(void)i;
	ray->map_x = (int)cube->player->pos_x;
	ray->map_y = (int)cube->player->pos_y;
	ray->delta_x = fabs(1 / ray->cos);
	ray->delta_y = fabs(1 / ray->sin);
	ray_steps(ray, cube->player);
	did_it_hit(ray, cube->config);
	// Corrección del ojo de pez
	if (ray->side == 0)
		ray->distance = (ray->side_x - ray->delta_x);
	else
		ray->distance = (ray->side_y - ray->delta_y);
}

void	paint_wall_solid(t_cube *cube, int i, double fixed_dist)
{
	int	start;
	int	end;
	int	y;
	int	color;

	color = 0x000000;
	start = HEIGHT / 2 - (HEIGHT / (2 * fixed_dist));
	end = HEIGHT / 2 + (HEIGHT / (2 * fixed_dist));
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	if (i < 0 || i >= WIDTH)
		return ;
	y = start;
	while (y <= end)
	{
		mlx_put_pixel(cube->img, i, y, color);
		y++;
	}
}

void	ft_raycaster(t_cube *cube)
{
	int		i;
	double	angle;
	double	start;
	double	fixed_dist;

	i = 0;
	angle = (FOV / WIDTH) * PI / 180;
	start = cube->config->map_view - (angle * (WIDTH / 2));
	while (i < WIDTH)
	{
		cube->ray[i].angle = start + (angle * i);
		cube->ray[i].cos = cos(cube->ray[i].angle);
		cube->ray[i].sin = sin(cube->ray[i].angle);
		ft_dda(&cube->ray[i], cube, i);
		fixed_dist = cube->ray[i].distance * cos(cube->ray[i].angle
				- cube->config->map_view);
		paint_wall_solid(cube, i, fixed_dist);
		i++;
	}
}
