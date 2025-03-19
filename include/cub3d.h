/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:06 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/19 13:13:54 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>

# define VALID_CHARS	"NEWS01\n\t "
# define VALID_NEIGHBORS "NEWS01"
# define FOV 60.0
# define PI 3.14159265359
# define WIDTH 1600
# define HEIGHT 900

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
	double	map_view;
}			t_config;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	player_view;
	int		player_count;
}				t_player;

typedef struct s_ray
{
	double	angle;
	double	cos;
	double	sin;
	double	side_x; 	//Distancia hasta el primer borde de celda en cada eje.
	double	side_y;
	double	delta_x; 	//Distancia para cruzar una celda en cada eje.
	double	delta_y;
	double	distance; 	//Variable implementada para corregir el ojo de pez que pudiera ocasionarse
	int		side; 		//Indica si hemos chocado con una pared en x o y
	int		map_x;
	int 	map_y;
	int		step_x; 	//Dirección en la que avanza el rayo (izquierda/derecha, arriba/abajo).
	int		step_y;	
}			t_ray;

typedef struct s_cube
{
	t_config	*config;
	t_ray		*ray;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*no_wall_i;
	mlx_image_t	*so_wall_i;
	mlx_image_t	*we_wall_i;
	mlx_image_t	*ea_wall_i;
	mlx_texture_t	*no_wall;
	mlx_texture_t	*so_wall;
	mlx_texture_t	*we_wall;
	mlx_texture_t	*ea_wall;
	mlx_image_t		*img;
}			t_cube;


/*INIT*/
t_cube		*init_cube(void);
t_ray		*init_ray(void);
t_player	*init_player(void);
t_ray		*init_ray(void);
/*INIT_MLX*/
int			init_mlx(t_cube *cube);
/*PARSE*/
void		check_extension(char *str);
void		read_map_file(char *filename, t_config *config);
void		ft_parse_map(t_cube *cube, char **map);
void		validate_rgb(t_config *config, char *color, int *values);
/*RAYCASTING*/
void		ray_steps(t_ray *ray, t_player *player);
void		did_it_hit(t_ray *ray, t_config *config);
void		ft_dda(t_ray *ray, t_cube *cube, int i);
void		ft_raycaster(t_cube *cube);
/*UTILS*/
char		*space_skip_save(char *str);
void		save_data(t_config *config);
void		save_routes(char **coord, char *route, t_config *config);
int			check_data(t_config *config);
void		set_player_view(t_cube *cube);
/*AUXILIAR FUNCTIONS*/
int			ft_isspace(char c);
int			ft_strempty(char *str);
void		save_map(int i, t_config *config, char **file);
int			ft_check_digit(char *str);
void		print_error(char *str, t_config *config);
/*FREE*/
void		free_matrix(char **str);
void		free_config(t_config *config);
void		free_mlx(t_cube *cube);

void paint_all(t_cube *game,int x, int y);
int	rgb(int r, int g, int b, int a);

#endif