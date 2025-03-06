/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:40:17 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/06 16:50:24 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_extension(char *str)
{
	int		len;
	char	*aux;

	len = ft_strlen(str);
	if (len <= 4)
	{
		ft_printf("Error: name map invalid\n");
		exit(1);
	}
	aux = ft_substr(str, len - 4, len);
	if (ft_strncmp(aux, ".cub", 4) != 0)
	{
		free(aux);
		ft_printf("Error: extension invalid\n");
		exit(1);
	}
	free(aux);
}

static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

static void	store_lines(int fd, t_config *config, int num_lines)
{
	char	*line;
	int		i;

	config->file = (char **)malloc(sizeof(char *) * (num_lines + 1));
	if (!config->file)
	{
		ft_printf("Error: malloc failed\n");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		config->file[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	config->file[i] = NULL;
}

void	read_map_file(char *filename, t_config *config)
{
	int	fd;
	int	num_lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: file could not be opened\n");
		exit(1);
	}
	num_lines = count_lines(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: file could not be opened\n");
		exit(1);
	}
	store_lines(fd, config, num_lines);
	close(fd);
}

void	save_data(t_config *config)
{
	char	**file;
	int		i;

	file = config->file;
	i = 0;
	while (file[i])
	{
		if (ft_strncmp("NO ", file[i], 3) == 0)
			save_routes(&config->no, space_skip_save(file[i] + 3), config);
		else if (ft_strncmp("SO ", file[i], 3) == 0)
			save_routes(&config->so, space_skip_save(file[i] + 3), config);
		else if (ft_strncmp("WE ", file[i], 3) == 0)
			save_routes(&config->we, space_skip_save(file[i] + 3), config);
		else if (ft_strncmp("EA ", file[i], 3) == 0)
			save_routes(&config->ea, space_skip_save(file[i] + 3), config);
		else if (ft_strncmp("F ", file[i], 2) == 0)
		save_routes(&config->f_rgb, space_skip_save(file[i] + 2), config);
		else if (ft_strncmp("C ", file[i], 2) == 0)
		save_routes(&config->c_rgb, space_skip_save(file[i] + 2), config);
		i++;
		if (config->data_saved >= 6)
			break ;
	}
	if (check_data(config))
		save_map(i, config, file);
}

void	validate_rgb(char *str, t_config *config, char **rgb_dest)
{
	char	**split;
	int		i;


	split = ft_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (!ft_check_digit(split[i]) || ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
		{
			free_matrix(split);
			print_error("Error: RGB value out of range\n", config);
		}
		i++;
	}
	free_matrix(split);
	*rgb_dest = ft_strdup(str);
}
