/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:49:56 by jceron-g          #+#    #+#             */
/*   Updated: 2025/02/26 16:33:02 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	while (config.file[i])
	{
		ft_printf("%s\n", config.file[i]);
		i++;
	}
	free_config(&config);
	return (0);
}
