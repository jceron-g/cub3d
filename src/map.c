/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:39:19 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/11 17:30:29 by jceron-g         ###   ########.fr       */
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
			if (!ft_strchr(VALID_NEIGHBORS, map[pos_i - 1][pos_j]))
				return (0);
			if (!ft_strchr(VALID_NEIGHBORS, map[pos_i + 1][pos_j]))
				return (0);
			if (!ft_strchr(VALID_NEIGHBORS, map[pos_i][pos_j - 1]))
				return (0);
			if (!ft_strchr(VALID_NEIGHBORS, map[pos_i][pos_j + 1]))
				return (0);
		}
	}
	return (1);
}

void	ft_parse_map(t_config *config, char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	j = 0;
	player_count = 0;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
			{
				print_error("Invalid char in map", config);
				return ;
			}
			if (ft_strchr("NSWE", map[i][j]))
			{
				player_count++;
				if (player_count > 1)
				{
					print_error("Error: More than one player detected\n", config);
					return ;
				}
			}
			if (check_neighbors(i, j, map))
				j++;
			else
			{
				ft_printf("Error: Found in i= %d j= %d a ", i, j);
				print_error("char in a not valid position\n", config);
				return ;
			}
		}
		j = 0;
	}
	if (player_count == 0)
	{
		print_error("Error: No player found in map\n", config);
		return ;
	}
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

