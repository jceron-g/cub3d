/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:49:56 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/19 12:31:53 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cube		*cube;
	cube = init_cube();
	if (argc != 2)
	{
		ft_printf("Error: Incorrect arguments\n");
		return (1);
	}
	check_extension(argv[1]);
	read_map_file(argv[1], cube->config);
	save_data(cube->config);
	ft_parse_map(cube, cube->config->map);
	validate_rgb(cube->config, cube->config->c_rgb, cube->config->c_int);
	validate_rgb(cube->config, cube->config->f_rgb, cube->config->f_int);
	set_player_view(cube);
	ft_raycaster(cube);
	init_mlx(cube);
	mlx_loop(cube->mlx);
	free_config(cube->config);
	return (0);
}
