/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:56:22 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/06 10:58:00 by jceron-g         ###   ########.fr       */
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

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	str = NULL;
}
