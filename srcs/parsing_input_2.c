/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:46 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/20 12:24:25 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_convertdir(t_game *game)
{
	game->wall.no = ft_substr(game->wall.no, ft_spacecount(game->wall.no),
			ft_strlen(game->wall.no) - (ft_spacecount(game->wall.no) + 1));
	game->wall.so = ft_substr(game->wall.so, ft_spacecount(game->wall.so),
			ft_strlen(game->wall.so) - (ft_spacecount(game->wall.so) + 1));
	game->wall.we = ft_substr(game->wall.we, ft_spacecount(game->wall.we),
			ft_strlen(game->wall.we) - (ft_spacecount(game->wall.we) + 1));
	game->wall.ea = ft_substr(game->wall.ea, ft_spacecount(game->wall.ea),
			ft_strlen(game->wall.ea) - (ft_spacecount(game->wall.ea) + 1));
	if (game->wall.no == NULL || game->wall.so == NULL
		|| game->wall.ea == NULL || game->wall.we == NULL)
		return (ft_freedir(game), 0);
	return (1);
}

int	ft_convertcolor(t_game *game)
{
	game->floor = ft_substr(game->floor, ft_spacecount(game->floor),
			ft_strlen(game->floor) - (ft_spacecount(game->floor) + 1));
	game->roof = ft_substr(game->roof, ft_spacecount(game->roof),
			ft_strlen(game->roof) - (ft_spacecount(game->roof) + 1));
	if (game->floor == NULL || game->roof == NULL)
		return (ft_freecol(game), 0);
	return (1);
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

int	ft_nbrcolor(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (game->floor[i])
	{
		if (game->floor[i] == ',')
			j++;
		i++;
	}
	i = 0;
	while (game->roof[i])
	{
		if (game->roof[i] == ',')
			k++;
		i++;
	}
	if (j != 2 || k != 2)
		return (0);
	return (1);
}

int	ft_vcolor(t_game *game, int i)
{
	int	j;
	int	k;

	if (ft_convertcolor(game) == 0)
		return (write(2, "Error\n color format", 19), 0);
	game->fcol = ft_split(game->floor, ',');
	game->rcol = ft_split(game->roof, ',');
	if (ft_nbrcolor(game) == 0 || ft_vcolor_suite(game->fcol) == 0
		|| ft_vcolor_suite(game->rcol) == 0)
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
