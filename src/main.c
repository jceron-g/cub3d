/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:49:56 by jceron-g          #+#    #+#             */
/*   Updated: 2025/08/08 13:21:35 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_parse(t_cube *cube, char **argv)
{
	check_extension(argv[1]);
	read_map_file(argv[1], cube->config);
	save_data(cube->config, cube, 0);
	ft_parse_map(cube, cube->config->map);
	validate_rgb(cube->config, cube->config->c_rgb, cube->config->c_int);
	validate_rgb(cube->config, cube->config->f_rgb, cube->config->f_int);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = param;
	key_press_control(keydata, cube);
	key_release_control(keydata, cube);
}

void	my_hook(void *param)
{
	t_cube	*cube;

	cube = param;
	player_movement(cube);
	paint_all(cube, 0, 0);
	ft_raycaster(cube);
}

int	main(int argc, char **argv)
{
	t_cube	*cube;

	cube = init_cube();
	if (argc != 2)
	{
		ft_printf("Error: Incorrect arguments\n");
		return (1);
	}
	ft_parse(cube, argv);
	set_player_view(cube);
	if (!init_mlx(cube))
	{
		ft_printf("Error: There is no file with that texture name.\n");
		free_and_exit(cube);
	}
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	paint_all(cube, 0, 0);
	mlx_image_to_window(cube->mlx, cube->img, 0, 0);
	ft_raycaster(cube);
	mlx_key_hook(cube->mlx, my_keyhook, cube);
	mlx_loop_hook(cube->mlx, my_hook, cube);
	mlx_close_hook(cube->mlx, (mlx_closefunc)free_and_exit, cube);
	mlx_loop(cube->mlx);
	return (0);
}
