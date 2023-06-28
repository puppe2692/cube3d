/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:46 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/28 14:59:51 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_convertdir(t_game *game)
{
	game->wall.no = ft_substr(game->wall.no, 3, ft_strlen(game->wall.no) - 4);
	game->wall.so = ft_substr(game->wall.so, 3, ft_strlen(game->wall.so) - 4);
	game->wall.we = ft_substr(game->wall.we, 3, ft_strlen(game->wall.we) - 4);
	game->wall.ea = ft_substr(game->wall.ea, 3, ft_strlen(game->wall.ea) - 4);
}

void	ft_convertcolor(t_game *game)
{
	game->floor = ft_substr(game->floor, 2, ft_strlen(game->floor) - 3);
	game->roof = ft_substr(game->roof, 2, ft_strlen(game->roof) - 3);
}

int	ft_vcolor_suite(char **hex)
{
	int	i;
	int	j;

	i = 0;
	while (hex[i] != NULL)
		i++;
	if (i != 3)
		return (0);
	i = -1;
	while (hex[++i] != NULL)
	{
		j = 0;
		while (hex[i][j] != '\0')
		{
			if (hex[i][j] < 48 || hex[i][j] > 57 || j > 2)
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_vcolor(t_game *game)
{
	int	i;
	int	j;
	int	k;

	ft_convertcolor(game);
	game->fcol = ft_split(game->floor, ',');
	game->rcol = ft_split(game->roof, ',');
	i = -1;
	if (ft_vcolor_suite(game->fcol) == 0 || ft_vcolor_suite(game->rcol) == 0)
	{
		write(2, "Error\n color format", 19);
		return (0);
	}
	while (++i < 3)
	{
		j = ft_atoi(game->fcol[i]);
		k = ft_atoi(game->rcol[i]);
		if (j < 0 || j > 255 || i < 0 || i > 255
			|| game->rcol[i] == NULL || game->fcol[i] == NULL)
		{
			write(2, "Error\n color format", 19);
			return (0);
		}
	}
	return (1);
}
