/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:56:22 by jceron-g          #+#    #+#             */
/*   Updated: 2025/08/08 12:37:52 by jceron-g         ###   ########.fr       */
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
	str = NULL;
}

void	free_config(t_config *config)
{
	if (!config)
		return ;
	free_matrix(config->file);
	free_matrix(config->map);
	free(config->f_rgb);
	free(config->c_rgb);
	free(config->no);
	free(config->so);
	free(config->we);
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
	if (cube->current_texture)
		mlx_delete_texture(cube->current_texture);
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
	free_config(cube->config);
	free_mlx(cube);
	free(cube->player);
	free(cube->ray);
	free(cube);
	exit(0);
}