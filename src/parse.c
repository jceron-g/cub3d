/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:40:17 by jceron-g          #+#    #+#             */
/*   Updated: 2025/02/26 15:48:39 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void check_extension(char *str)
{
	int		len;
	char	*aux;

	len = ft_strlen(str);
	if (len <= 4)
	{
		ft_printf("Error: name map invalid\n");
		exit(1);
	}
	aux = ft_substr(str, len - 4, len);
	if (ft_strncmp(aux, ".cub", 4) != 0)
	{
		free(aux);
		ft_printf("Error: extension invalid\n");
		exit(1);
	}
	free(aux);
}

