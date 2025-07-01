#include "../include/cub3d.h"

int	key_press_control(mlx_key_data_t keydata, t_cube *cube)
{
  t_player  *player;

  player = cube->player;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		//añadir función de cerrar todo
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		player->rotate = -1;
		cube->config->map_view -= ROTATE_S;
		printf("Llego!\n");
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		player->rotate = 1;
		cube->config->map_view += ROTATE_S;
		printf("Llego!\n");
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player->move_y = 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player->move_x = -1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player->move_y = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player->move_x = 1;
	return (0);
}

int	key_release_control(mlx_key_data_t keydata, t_cube *cube)
{
  t_player  *player;
  
  player = cube->player;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		player->move_y = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		player->move_y = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		player->move_x = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		player->move_x = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		player->rotate = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		player->rotate = 0;
	return (0);
}
