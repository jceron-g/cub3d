#include "../include/cub3d.h"

void	rotate_in_direction(t_cube *cube, double rot_speed)
{
	t_player	*player;
	double		aux_x;

	player = &cube->player;
	aux_x = p->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y * sin(rot_speed);
	player->dir_y = aux_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	aux_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y * sin(rot_speed);
	player->plane_y = aux_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

void	player_rotation(t_cube *cube, double rotation_dir)
{
	double	rot_speed;

	rot_speed = ROTATION_SPEED * rotation_dir;
	rotate_in_direction(cube, rot_speed);
}