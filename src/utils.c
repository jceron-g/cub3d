/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:47:37 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/11 14:49:22 by malena-b         ###   ########.fr       */
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
