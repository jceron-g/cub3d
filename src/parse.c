/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:40:17 by jceron-g          #+#    #+#             */
/*   Updated: 2025/02/26 16:37:02 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void check_extension(char *str)
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
	size_t	len;

	config->file = (char **)malloc(sizeof(char *) * (num_lines + 1));
	if (!config->file)
	{
		ft_printf("Error: No se pudo reservar memoria\n");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
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
		ft_printf("Error: No se pudo abrir el archivo\n");
		exit(1);
	}
	num_lines = count_lines(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: No se pudo abrir el archivo\n");
		exit(1);
	}
	store_lines(fd, config, num_lines);
	close(fd);
}