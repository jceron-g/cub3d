/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:36:02 by jceron-g          #+#    #+#             */
/*   Updated: 2025/08/08 12:37:52 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_strempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%c\n", str[i]);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_error(char *str, t_config *config)
{
	ft_putstr_fd(str, 2);
	if (config)
		free_config(config);
	exit(1);
}

void	print_error_cube(char *str, t_cube *cube)
{
	ft_putstr_fd(str, 2);
	if (cube)
	{
		if (cube->config)
			free_config(cube->config);
		if (cube->player)
			free(cube->player);
		if (cube->ray)
			free(cube->ray);
		free(cube);
	}
	exit(1);
}
