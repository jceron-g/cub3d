/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:30:57 by malena-b          #+#    #+#             */
/*   Updated: 2025/03/11 14:54:12 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
			{
				print_error("Invalid char in map", config);
				return ;
			}
			if (check_neighbors(i, j, map))
				j++;
			else
			{
				ft_printf("ERROR: Found in i=%d j=%d a ", i, j);
				print_error("char in a not valid position\n", config);
				return ;
			}
		}
		j = 0;
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
			print_error("ERROR: Not a valid character in RGB value.\n", config);
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		print_error("ERROR: Too many values in RGB.\n", config);
	splitted = ft_split(color, ',');
	values[0] = ft_atoi(splitted[0]);
	values[1] = ft_atoi(splitted[1]);
	values[2] = ft_atoi(splitted[2]);
	free_matrix(splitted);
}
