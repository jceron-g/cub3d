#include "../include/cub3d.h"

void    initialize_textures(t_cube *cube)
{
    cube->no_wall = NULL;
    cube->so_wall = NULL;
    cube->we_wall = NULL;
    cube->ea_wall = NULL;
}

int load_texture(t_cube *cube)
{
    initialize_textures(cube);
    cube->no_wall_i = mlx_load_png(cube->config->no);
    cube->so_wall_i = mlx_load_png(cube->config->so);
    cube->we_wall_i = mlx_load_png(cube->config->we);
    cube->ea_wall_i = mlx_load_png(cube->config->ea);
    if (!cube->no_wall_i || !cube->so_wall_i || !cube->we_wall_i || !cube->ea_wall_i)
        return (0);
    cube->no_wall = mlx_texture_to_image(cube->mlx, cube->no_wall_i);
    cube->so_wall = mlx_texture_to_image(cube->mlx, cube->so_wall_i);
    cube->we_wall = mlx_texture_to_image(cube->mlx, cube->we_wall_i);
    cube->ea_wall = mlx_texture_to_image(cube->mlx, cube->ea_wall_i);
    return (1);
}

int    init_mlx(t_cube *cube)
{
    cube->mlx = mlx_init(WIDTH, HEIGHT, "Window", true);
    if (load_texture(cube) == 0)
		return (0);
	return (1);
}