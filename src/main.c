/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:49:56 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/12 11:18:01 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_config	config;

	ft_bzero(&config, sizeof(config));
	if (argc != 2)
	{
		ft_printf("Error: Incorrect arguments\n");
		return (1);
	}
	check_extension(argv[1]);
	read_map_file(argv[1], &config);
	save_data(&config);
	ft_parse_map(&config, config.map);
	validate_rgb(&config, config.c_rgb, config.c_int);
	validate_rgb(&config, config.f_rgb, config.f_int);
	free_config(&config);
	return (0);
}
