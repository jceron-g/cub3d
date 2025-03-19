/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:33:17 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/19 12:36:42 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_config	*init_config(void)
{
	t_config *config;

	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	ft_bzero(config, sizeof(t_config));
	return (config);
	
}

t_player	*init_player(void)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	ft_bzero(player, sizeof(t_player));
	return (player);
}


t_ray	*init_ray(void)
{
	t_ray *ray;

	ray = (t_ray *)malloc(sizeof(t_ray) * WIDTH);
	if (!ray)
		return (NULL);
	ft_bzero(ray, sizeof(t_ray) * WIDTH);
	return (ray);
}



t_cube	*init_cube(void)
{
	t_cube *cube;

	cube = (t_cube *)malloc(sizeof(t_cube));
	if (!cube)
		return (NULL);
	ft_bzero(cube, sizeof(t_cube));
	cube->config = init_config();
	cube->player = init_player();
	cube->ray = init_ray();
	if (!cube->config || !cube->player || !cube->ray)
	{
		free_config(cube->config);
		free(cube->player);
		free(cube->ray);
		free(cube);
		return (NULL);
	}
	return (cube);
}

