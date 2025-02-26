/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:49:56 by jceron-g          #+#    #+#             */
/*   Updated: 2025/02/26 15:47:13 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_config config;
	ft_bzero(&config,sizeof(config));
	if(argc != 2)
	{
		ft_printf("Error:Numeros de argumentos incorrecto\n");
		return(1);
		/*Liberar todo lo que tengo cuando de error.*/
	}
	check_extension(argv[1]);
	
}