/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:39:19 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/14 12:57:50 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	save_map(int i, t_config *config, char **file)
{
	int	size;
	int	j;

	size = i;
	while (file[i][0] == '\n')
		i++;
	while (file[size])
		size++;
	config->map = (char **)malloc(sizeof(char *) * (size - i + 1));
	if (!config->map)
		return ;
	j = 0;
	while (file[i])
		config->map[j++] = ft_strdup(file[i++]);
	config->map[j] = NULL;
	j = -1;
	while (config->map[++j])
	{
		i = 0;
		while (config->map[j][i++])
		{
			if (!ft_strchr(VALID_CHARS, config->map[j][i]))
				print_error("Error: Invalid characters detected\n", config);
		}
	}
}

int	check_neighbors(int pos_i, int pos_j, char **map)
{
	if (ft_strchr(VALID_NEIGHBORS, map[pos_i][pos_j]))
	{
		if (map[pos_i][pos_j] != '1')
		{
			if (pos_i == 0 || pos_j == 0)
				return (0);
			if (!(map[pos_i - 1]) || !(map[pos_i - 1][pos_j]) ||
				!ft_strchr(VALID_NEIGHBORS, map[pos_i - 1][pos_j]))
				return (0);
			if (!(map[pos_i + 1]) || !(map[pos_i + 1][pos_j]) ||
				!ft_strchr(VALID_NEIGHBORS, map[pos_i + 1][pos_j]))
				return (0);
			if (!(map[pos_i][pos_j - 1]) ||
				!ft_strchr(VALID_NEIGHBORS, map[pos_i][pos_j - 1]))
				return (0);
			if (!(map[pos_i][pos_j + 1]) ||
				!ft_strchr(VALID_NEIGHBORS, map[pos_i][pos_j + 1]))
				return (0);
		}
	}
	return (1);
}

void	check_player(char coordinate, int x, int y, t_cube *cube)
{
	cube->player->player_view = coordinate;
	cube->player->pos_x = x + 0.5; //Se pone el 0.5 extra para empezar justo en el medio del cuadrado
	cube->player->pos_y = y + 0.5;
	cube->player->player_count++;
}

void	ft_parse_map(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
				print_error("Error: Invalid char in map", cube->config);
			if (ft_strchr("NSWE", map[i][j]))
				check_player(map[i][j], j, i, cube);
			if (!check_neighbors(i, j, map))
			{
				ft_printf("Error: Found in i= %d j= %d a ", i, j);
				print_error("char in a not valid position\n", cube->config);
			}
		}
	}
	printf("Player count: %d is in position x = %f y = %f and the letter is %f\n",cube->player->player_count, cube->player->pos_x, cube->player->pos_y, cube->player->player_view);
	if (cube->player->player_count != 1)
		print_error("Error: Invalid number of players\n", cube->config);
}

void	validate_rgb(t_config *config, char *color, int *values)
{
	int		i;
	int		count;
	char	**splitted;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ',' && color[i] != '\n')
			print_error("Error: Not a valid character in RGB value.\n", config);
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		print_error("Error: Too many values in RGB.\n", config);
	splitted = ft_split(color, ',');
	values[0] = ft_atoi(splitted[0]);
	values[1] = ft_atoi(splitted[1]);
	values[2] = ft_atoi(splitted[2]);
	free_matrix(splitted);
}

