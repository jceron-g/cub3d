#include "../include/cub3d.h"

int	move_forward(t_cube *cube)
{
  t_player  *player;
	double	new_x;
	double	new_y;

  player = cube->player;
	new_x = player.pos_x + player.dir_x * MOVE_SPEED;
	new_y = player.pos_y + player.dir_y * MOVE_SPEED;
	return (0);
}

int	move_backward(t_cube *cube)
{
  t_player  *player;
	double	new_x;
	double	new_y;

  player = cube->player;
	new_x = player.pos_x - player.dir_x * MOVE_SPEED;
	new_y = player.pos_y - player.dir_y * MOVE_SPEED;
	return (0);
}

int	move_left(t_cube *cube)
{
  t_player  *player;
	double	new_x;
	double	new_y;

  player = cube->player;
	new_x = player.pos_x + player.dir_y * MOVE_SPEED;
	new_y = player.pos_y - player.dir_x * MOVE_SPEED;
	return (0);
}

int	move_right(t_cube *cube)
{
  t_player  *player;
	double	new_x;
	double	new_y;

  player = cube->player;
	new_x = player.pos_x - player.dir_y * MOVESPEED;
	new_y = player.pos_y + player.dir_x * MOVESPEED;
	return (0);
}

void	player_movement(t_cube *cube)
{
  t_player  *player;

  player = cube->player;
	if (player.move_y == 1)
		move_forward(cube);
	if (player.move_y == -1)
		move_backward(cube);
	if (player.move_x == -1)
		move_left(cube);
	if (player.move_x == 1)
		move_right(cube);
	//if (player.rotate != 0)
		//rotate_player(cube, player.rotate);
}
