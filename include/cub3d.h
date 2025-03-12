/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:06 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/12 10:52:13 by jceron-g         ###   ########.fr       */
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
	int		f_int[3];
	int		c_int[3];
	char	**map;
	char	**file;
	int		data_saved;
	int		error;
}			t_config;

typedef struct s_ray
{
	double	angle;
	double	cos;
	double	sin;
	double	side_x; //Distancia hasta el primer borde de celda en cada eje.
	double	side_y;
	double	delta_x; //Distancia para cruzar una celda en cada eje.
	double	delta_y;
	int		step_x; //Dirección en la que avanza el rayo (izquierda/derecha, arriba/abajo).
	int		step_y;	
}			t_ray;

typedef struct s_cube
{
	t_config	*config;
	t_ray		*ray;
	mlx_t		*mlx;
}			t_cube;

# define VALID_CHARS	"NOWS01\n\t "
# define VALID_NEIGHBORS "NOWS01"
# define FOV 60.0
# define PI 3.14159265
# define WIDTH 1600
# define HEIGHT 900

/*PARSE*/
void	check_extension(char *str);
void	read_map_file(char *filename, t_config *config);
void	ft_parse_map(t_config *config, char **map);
void	validate_rgb(t_config *config, char *color, int *values);
/*UTILS*/
char	*space_skip_save(char *str);
void	save_data(t_config *config);
void	save_routes(char **coord, char *route, t_config *config);
int		check_data(t_config *config);
/*AUXILIAR FUNCTIONS*/
int		ft_isspace(char c);
int		ft_strempty(char *str);
void	save_map(int i, t_config *config, char **file);
int		ft_check_digit(char *str);
void	print_error(char *str, t_config *config);
/*FREE*/
void	free_matrix(char **str);
void	free_config(t_config *config);


#endif