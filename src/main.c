/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:49:56 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/05 13:12:28 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_config	config;
	int			i;

	ft_bzero(&config, sizeof(config));
	if (argc != 2)
	{
		ft_printf("Error: Incorrect arguments\n");
		return (1);
	}
	check_extension(argv[1]);
	read_map_file(argv[1], &config);
	i = 0;
	// while (config.file[i])
	// {
	// 	ft_printf("%s\n", config.file[i]);
	// 	i++;
	// }
	save_data(&config);
	// printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %s\nC: %s\n", config.no, config.so, config.we, config.ea, config.f_rgb, config.c_rgb);
	// printf("Data saved: %d\n", config.data_saved);
	i = 0;
	while (config.map[i])
	{
		ft_printf("%s", config.map[i]);
		i++;
	}
	free_config(&config);
	return (0);
}
