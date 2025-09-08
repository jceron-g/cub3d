/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:03:29 by jceron-g          #+#    #+#             */
/*   Updated: 2025/09/08 17:32:52 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_textures(t_cube *cube)
{
	cube->no_wall = NULL;
	cube->so_wall = NULL;
	cube->we_wall = NULL;
	cube->ea_wall = NULL;
	cube->current_texture = NULL;
	cube->no_wall_i = NULL;
	cube->so_wall_i = NULL;
	cube->we_wall_i = NULL;
	cube->ea_wall_i = NULL;
}

int	load_texture(t_cube *cube)
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;

	initialize_textures(cube);
	north = mlx_load_png(cube->config->no);
	south = mlx_load_png(cube->config->so);
	west = mlx_load_png(cube->config->we);
	east = mlx_load_png(cube->config->ea);
	cube->no_wall = north;
	cube->so_wall = south;
	cube->we_wall = west;
	cube->ea_wall = east;
	if (!north || !south || !west || !east)
		return (0);
	return (1);
}

int	rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	paint_all(t_cube *game, int x, int y)
{
	int	rgb_ceiling;
	int	rgb_floor;

	rgb_ceiling = rgb(game->config->c_int[0], game->config->c_int[1],
			game->config->c_int[2], 255);
	rgb_floor = rgb(game->config->f_int[0], game->config->f_int[1],
			game->config->f_int[2], 255);
	while (HEIGHT / 2 > y)
	{
		x = 0;
		while (WIDTH > x++)
			mlx_put_pixel(game->img, x, y, rgb_ceiling);
		y++;
	}
	while (HEIGHT > y)
	{
		x = 0;
		while (WIDTH > x++)
			mlx_put_pixel(game->img, x, y, rgb_floor);
		y++;
	}
}

int	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "Window", true);
	if (!cube->mlx || load_texture(cube) == 0)
		return (0);
	return (1);
}
