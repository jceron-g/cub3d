/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:56:22 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/06 10:58:00 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_config(t_config *config)
{
	int	i;

	if (config->file)
	{
		i = 0;
		while (config->file[i])
		{
			free(config->file[i]);
			i++;
		}
		free(config->file);
	}
}

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

void	free_mlx(t_cube *cube)
{
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
	if (cube->mlx)
		mlx_terminate(cube->mlx);
}
