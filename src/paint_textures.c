/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:52 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:16:08 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_texture(t_ray *ray, t_cube *game)
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

static uint32_t	get_tex_color(mlx_texture_t *tex, int x, int y)
{
	uint32_t	color;

	color = *(uint32_t *)(tex->pixels + (y * tex->width + x) * 4);
	color = (color & 0xff000000) >> 24 | (color & 0x00ff0000) >> 8
		| (color & 0x0000ff00) << 8 | (color & 0x000000ff) << 24;
	return (color);
}

void	paint_texture(t_cube *game, t_ray *ray, int i)
{
	int			y;
	uint32_t	color;

	y = ray->start_two;
	while (y < ray->end_two)
	{
		ray->tex_y = (int)((y - ray->start) * game->current_texture->height
				/ (ray->end - ray->start));
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= (int)game->current_texture->height)
			ray->tex_y = (int)game->current_texture->height - 1;
		color = get_tex_color(game->current_texture, ray->tex_x, ray->tex_y);
		mlx_put_pixel(game->img, i, y, color);
		y++;
	}
}

void	paint_wall(t_cube *game, t_ray *ray, int i, double distance_corrected)
{
	ray->start = HEIGHT / 2 - (WIDTH / (2 * distance_corrected));
	ray->end = HEIGHT / 2 + (WIDTH / (2 * distance_corrected));
	if (ray->start < 0)
		ray->start_two = 0;
	else
		ray->start_two = ray->start;
	if (ray->end >= HEIGHT)
		ray->end_two = HEIGHT;
	else
		ray->end_two = ray->end;
	set_texture(ray, game);
	paint_texture(game, ray, i);
}
