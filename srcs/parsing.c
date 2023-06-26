/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:00:19 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/26 16:23:11 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_includes.h"

int	ft_vwronginput(t_game *game)
{
	int	i;

	i = 0;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
	{
		if (strncmp(game->input[i], "NO ", 3)
			&& strncmp(game->input[i], "SO ", 3)
			&& strncmp(game->input[i], "WE ", 3)
			&& strncmp(game->input[i], "EA ", 3)
			&& strncmp(game->input[i], "F ", 2)
			&& strncmp(game->input[i], "J ", 2))
			return (0);
		i++;
	}
	return (1);
}

int	ft_vinput(t_game *game)
{
	if (ft_vwronginput(game) == 0)
	{
		write(2, "Error\n invalid input", 20);
		return (0);
	}
	if (game->vinputnbr != 6)
	{
		write(2, "Error\n input nbr of placement, ", 31);
		write(2, "verify you have the 6 correct ", 30);
		write(2, "inputs placed before the map\n", 29);
		return (0);
	}
	if (game->north == NULL || game->south == NULL || game->west == NULL
		|| game->east == NULL || game->floor == NULL || game->roof == NULL)
	{
		write(2, "Error\n input in double\n", 23);
		return (0);
	}
}

int	ft_parsing(t_game *game)
{
	if (ft_vinput(game) == 0)
	{
		write(2, "Error\n invalid map shape", 24);
		return (0);
	}
	if (ft_velem(game->map_str, game) == 0)
	{
		write(2, "Error\n invalid map element", 26);
		return (0);
	}
	if (ft_vwall(game) == 0)
	{
		write(2, "Error\n invalid map wall", 23);
		return (0);
	}
	if (ft_vpath(game) == 0)
	{
		write(2, "Error\n invalid map no path", 26);
		return (0);
	}
	return (1);
}
