/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:47:37 by jceron-g          #+#    #+#             */
/*   Updated: 2025/02/26 16:31:20 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_config(t_config *config)
{
	int	i;

	if (config->file)
	{
		i = 0;
		while (config->file[i])
		{
			free(config->file[i]);
			i++;
		}
		free(config->file);
	}
}