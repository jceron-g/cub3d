/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:06 by jceron-g          #+#    #+#             */
/*   Updated: 2025/07/15 20:37:06 by jceron-g         ###   ########.fr       */
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
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.025
# define ROTATE_S 0.037

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
	int		move_x;
	int		move_y;
	int		rotate;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_ray
{
	double	angle;
	double	cos;
	double	sin;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	distance;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		start;
	int		end;
	int		start_two;
	int		end_two;
}	t_ray;

typedef struct s_cube
{
	t_config		*config;
	t_ray			*ray;
	t_player		*player;
	mlx_t			*mlx;
	mlx_image_t		*no_wall_i;
	mlx_image_t		*so_wall_i;
	mlx_image_t		*we_wall_i;
	mlx_image_t		*ea_wall_i;
	mlx_texture_t	*no_wall;
	mlx_texture_t	*so_wall;
	mlx_texture_t	*we_wall;
	mlx_texture_t	*ea_wall;
	mlx_image_t		*img;
	mlx_texture_t	*current_texture;
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
void		free_and_exit(t_cube *cube);
/*MOVEMENT*/
void		player_movement(t_cube *cube);
void		rotate_player(t_cube *cube, double rotation_dir);
int			key_press_control(mlx_key_data_t keydata, t_cube *cube);
int			key_press_control(mlx_key_data_t keydata, t_cube *cube);
int			key_release_control(mlx_key_data_t keydata, t_cube *cube);

void		paint_all(t_cube *game, int x, int y);
int			rgb(int r, int g, int b, int a);
void		paint_wall(t_cube *game, t_ray *ray, int i,
				double distance_corrected);
void		set_texture(t_ray *ray, t_cube *game);
void		paint_texture(t_cube *game, t_ray *ray, int i);
int			move_forward(t_cube *cube);
int			move_backward(t_cube *cube);
int			move_left(t_cube *cube);
int			move_right(t_cube *cube);
void		set_player_view_side(t_cube *cube);

#endif