/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacer <jacer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:52 by jceron-g          #+#    #+#             */
/*   Updated: 2025/06/22 18:32:00 by jacer            ###   ########.fr       */
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
	if (ray->side == 0)
		ray->distance = (ray->side_x - ray->delta_x);
	else
		ray->distance = (ray->side_y - ray->delta_y);
}

void set_texture(t_ray *ray, t_cube *game)
{
	if (ray->side == 0)
	{
		ray->wall_x = game->player->pos_y + ray->distance * ray->sin;
		if (ray->step_x == -1)
			game->current_texture = game->no_wall;
		else
			game->current_texture = game->so_wall;
	}
	else
	{
		ray->wall_x = game->player->pos_x + ray->distance * ray->cos;
		if (ray->step_y == -1)
			game->current_texture = game->we_wall;
		else
			game->current_texture = game->ea_wall;
	}
	ray->wall_x -= floor(ray->wall_x);
	if (ray->wall_x < 0)
		ray->wall_x += 1.0;
	ray->tex_x = (int)(ray->wall_x * game->current_texture->width);
	if (ray->tex_x >= (int)game->current_texture->width)
		ray->tex_x = (int)game->current_texture->width - 1;
	if (ray->tex_x < 0)
		ray->tex_x = 0;
}

static uint32_t get_tex_color(mlx_texture_t *tex, int x, int y)
{
	uint32_t color;

	color = *(uint32_t *)(tex->pixels + (y * tex->width + x) * 4);
	color = (color & 0xff000000) >> 24 | (color & 0x00ff0000) >> 8 |
			(color & 0x0000ff00) << 8 | (color & 0x000000ff) << 24;
	return (color);
}

void paint_texture(t_cube *game, t_ray *ray, int i)
{
	int y;
	uint32_t color;

	y = ray->start;
	while (y < ray->end)
	{
		ray->tex_y = (int)((y - ray->start) * game->current_texture->height / (double)(ray->end - ray->start));
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= (int)game->current_texture->height)
			ray->tex_y = (int)game->current_texture->height - 1;
		color = get_tex_color(game->current_texture, ray->tex_x, ray->tex_y);
		mlx_put_pixel(game->img, i, y, color);
		y++;
	}
}

void paint_wall(t_cube *game, t_ray *ray, int i, double distance)
{
	double distance_corrected;

	distance_corrected = distance * cos(ray->angle - game->config->map_view);
	if (distance_corrected < 0.0001)
		distance_corrected = 0.0001;
	ray->start = -((int)(HEIGHT / distance_corrected)) / 2 + HEIGHT / 2;
	ray->end = ((int)(HEIGHT / distance_corrected)) / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	set_texture(ray, game);
	paint_texture(game, ray, i);
}

void ft_raycaster(t_cube *cube)
{
	int		 i;
	double angle;
	double start;

	i = 0;
	angle = (FOV / WIDTH) * PI / 180;
	start = cube->config->map_view - (angle * (WIDTH / 2));
	while (i < WIDTH)
	{
		cube->ray[i].angle = start + (angle * i);
		cube->ray[i].cos = cos(cube->ray[i].angle);
		cube->ray[i].sin = sin(cube->ray[i].angle);
		ft_dda(&cube->ray[i], cube, i);
		set_texture(&cube->ray[i], cube);
		paint_wall(cube, &cube->ray[i], i, cube->ray[i].distance);
		i++;
	}
}
