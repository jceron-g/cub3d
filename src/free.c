/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:56:22 by jceron-g          #+#    #+#             */
/*   Updated: 2025/09/09 13:15:42 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

void	free_config(t_config *config)
{
	if (!config)
		return ;
	if (config->file)
		free_matrix(config->file);
	if (config->map)
		free_matrix(config->map);
	if (config->f_rgb)
		free(config->f_rgb);
	if (config->c_rgb)
		free(config->c_rgb);
	if (config->no)
		free(config->no);
	if (config->so)
		free(config->so);
	if (config->we)
		free(config->we);
	if (config->ea)
		free(config->ea);
	free(config);
}

void	free_mlx(t_cube *cube)
{
	if (!cube)
		return ;
	if (cube->no_wall)
		mlx_delete_texture(cube->no_wall);
	if (cube->so_wall)
		mlx_delete_texture(cube->so_wall);
	if (cube->we_wall)
		mlx_delete_texture(cube->we_wall);
	if (cube->ea_wall)
		mlx_delete_texture(cube->ea_wall);
	if (cube->no_wall_i)
		mlx_delete_image(cube->mlx, cube->no_wall_i);
	if (cube->so_wall_i)
		mlx_delete_image(cube->mlx, cube->so_wall_i);
	if (cube->we_wall_i)
		mlx_delete_image(cube->mlx, cube->we_wall_i);
	if (cube->ea_wall_i)
		mlx_delete_image(cube->mlx, cube->ea_wall_i);
	if (cube->img)
		mlx_delete_image(cube->mlx, cube->img);
	if (cube->mlx)
		mlx_terminate(cube->mlx);
}

void	free_and_exit(t_cube *cube)
{
	if (!cube)
		exit(0);
	if (cube->config)
	{
		free_config(cube->config);
		cube->config = NULL;
	}
	free_mlx(cube);
	if (cube->player)
	{
		free(cube->player);
		cube->player = NULL;
	}
	if (cube->ray)
	{
		free(cube->ray);
		cube->ray = NULL;
	}
	free(cube);
	exit(0);
}
