/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:39:19 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/11 14:55:16 by malena-b         ###   ########.fr       */
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


