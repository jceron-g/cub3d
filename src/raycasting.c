/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:52 by jceron-g          #+#    #+#             */
/*   Updated: 2025/03/13 16:11:32 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

/*Funcion que hay que creerse*/
void	ray_steps(t_ray *ray, t_player *player)
{
	if (ray->cos < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->sin < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
    printf("%f\n", ray->side_y);
}

// void	DDA_algorithm(t_ray *ray, t_cube *cube, int i)
// {

// 	ray->map_x = (int)cube->player->pos_x;
// 	ray->map_y = (int)cube->player->pos_y;
// 	ray->delta_x = fabs(1 / ray->cos);
// 	ray->delta_y = fabs(1 / ray->sin);
// 	ray_steps(ray, cube->player);
// }

// void ft_raycaster(t_cube *cube)
// {
//     double angle;
    
//     angle = (FOV/WIDTH) * PI / 180; //Esto seria el angulo del primer rayo que sale pasado a radianes
// } 
