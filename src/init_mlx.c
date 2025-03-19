#include "../include/cub3d.h"

void	initialize_textures(t_cube *cube)
{
	cube->no_wall = NULL;
	cube->so_wall = NULL;
	cube->we_wall = NULL;
	cube->ea_wall = NULL;
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
	if (!north|| !south|| !west	|| !east)
		return (0);
/* 	cube->no_wall_i = mlx_texture_to_image(cube->mlx, cube->no_wall);
	cube->so_wall_i = mlx_texture_to_image(cube->mlx, cube->so_wall);
	cube->we_wall_i = mlx_texture_to_image(cube->mlx, cube->we_wall);
	cube->ea_wall_i = mlx_texture_to_image(cube->mlx, cube->ea_wall); */
	return (1);
}

int	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "Window", true);
	if (!cube->mlx || load_texture(cube) == 0)
		return (0);
	return (1);
}

