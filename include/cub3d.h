/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:06 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/05 13:00:07 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_rgb;
	char	*c_rgb;
	char	**map;
	char	**file;
	int		data_saved;
	int		error;
}			t_config;

# define VALID_CHARS	"NOWS01\n\t "

/*PARSE*/
void	check_extension(char *str);
void	read_map_file(char *filename, t_config *config);
void	free_config(t_config *config);
/*UTILS*/
char	*space_skip_save(char *str);
void	save_data(t_config *config);
void	save_routes(char **coord, char *route, t_config *config);
int		check_data(t_config *config);
/*AUXILIAR FUNCTIONS*/
int		ft_isspace(char c);
int		ft_strempty(char *str);
void	save_map(int i, t_config *config, char **file);


#endif