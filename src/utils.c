/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:47:37 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:27:42 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*space_skip_save(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (ft_strdup(str + i));
}

void	print_error_and_exit(char	*error, t_cube	*cube)
{
	ft_printf("%s\n", error);
	free_and_exit(cube);
}

void	save_routes(char **coord, char *route, t_config *config)
{
	if (!*coord)
		*coord = route;
	config->data_saved++;
}

int	check_data(t_config *config)
{
	if (!config->no)
		return (0);
	else if (!config->so)
		return (0);
	else if (!config->ea)
		return (0);
	else if (!config->we)
		return (0);
	else if (!config->c_rgb)
		return (0);
	else if (!config->f_rgb)
		return (0);
	return (1);
}

void	player_movement(t_cube *cube)
{
	t_player	*player;

	player = cube->player;
	if (player->move_y == 1)
		move_forward(cube);
	if (player->move_y == -1)
		move_backward(cube);
	if (player->move_x == -1)
		move_left(cube);
	if (player->move_x == 1)
		move_right(cube);
	if (player->rotate != 0)
		rotate_player(cube, player->rotate);
}
