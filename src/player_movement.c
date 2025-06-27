#include "../include/cub3d.h"
#include <math.h>
//#define ROT_SPEED 0.05

static int is_wall(t_cube *cube, double x, double y)
{
	int mx;
	int my;

	mx = x;
	my = y;
	if (cube->config->map[my][mx] == '1')
		return 1;
	return 0;
}

int move_forward(t_cube *cube)
{
	t_player *player;
	double new_x;
	double new_y;

	player = cube->player;
	new_x = player->pos_x + player->dir_x * MOVE_SPEED;
	new_y = player->pos_y + player->dir_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return 0;
}

int move_backward(t_cube *cube)
{
	t_player *player;
	double new_x;
	double new_y;

	player = cube->player;
	new_x = player->pos_x - player->dir_x * MOVE_SPEED;
	new_y = player->pos_y - player->dir_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return 0;
}

int move_left(t_cube *cube)
{
	t_player *player;
	double new_x;
	double new_y;

	player = cube->player;
	new_x = player->pos_x + player->plane_x * MOVE_SPEED;
	new_y = player->pos_y + player->plane_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return 0;
}

int move_right(t_cube *cube)
{
	t_player *player;
	double new_x;
	double new_y;

	player = cube->player;
	new_x = player->pos_x - player->plane_x * MOVE_SPEED;
	new_y = player->pos_y - player->plane_y * MOVE_SPEED;
	if (!is_wall(cube, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!is_wall(cube, player->pos_x, new_y))
		player->pos_y = new_y;
	return 0;
}

/*void rotate_player(t_cube *cube, double rotation_dir)
{
	t_player *player;
	double old_dir_x;
	double old_plane_x;
	double rot;

	player = cube->player;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	rot = rotation_dir * ROT_SPEED;
	player->dir_x = player->dir_x * cos(rot) - player->dir_y * sin(rot);
	player->dir_y = old_dir_x * sin(rot) + player->dir_y * cos(rot);
	player->plane_x = player->plane_x * cos(rot) - player->plane_y * sin(rot);
	player->plane_y = old_plane_x * sin(rot) + player->plane_y * cos(rot);
}*/

void player_movement(t_cube *cube)
{
	t_player *player;

	player = cube->player;
	if (player->move_y == 1)
		move_forward(cube);
	if (player->move_y == -1)
		move_backward(cube);
	if (player->move_x == -1)
		move_left(cube);
	if (player->move_x == 1)
		move_right(cube);
	if (player->rotate != 0)
		rotate_player(cube, player->rotate);
}
