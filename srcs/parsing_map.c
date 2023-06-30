/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:09:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/30 15:59:10 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_vmapinput(t_game *game)
{
	int	i;
	int	j;
	int	pers;

	i = -1;
	pers = 0;
	while (game->map.map[++i] != NULL)
	{
		j = -1;
		while (game->map.map[i][++j] != '\0')
		{
			if (game->map.map[i][j] != ' ' && game->map.map[i][j] != '1'
				&& game->map.map[i][j] != '0' && game->map.map[i][j] != 'N'
				&& game->map.map[i][j] != 'S' && game->map.map[i][j] != 'E'
				&& game->map.map[i][j] != 'W')
				return (write(2, "Error\n invalid map input", 24), 0);
			if (game->map.map[i][j] != 'N' && game->map.map[i][j] != 'S'
				&& game->map.map[i][j] != 'E' && game->map.map[i][j] != 'W')
				pers++;
			if (pers > 1)
				return (write(2, "Error\n too many players", 23), 0);
		}
	}
	if (pers == 0)
		return (write(2, "Error\n player is missing", 24), 0);
}

int	ft_vmapwall_2(t_game *game, int i, int j)
{
	while (game->map.map[++i + 1] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] == ' ')
			j++;
		if (game->map.map[i][j] != '1')
			return (write(2, "Error\n invalid map wall", 23), 0);
		while (game->map.map[i][j] == '\0')
		{
			if ((game->map.map[i - 1][j] == ' '
				|| game->map.map[i - 1][j] == '\0'
				|| game->map.map[i + 1][j] == ' '
				|| game->map.map[i + 1][j] == '\0')
				&& game->map.map[i][j] != '1')
				return (write(2, "Error\n invalid map wall", 23), 0);
			if (game->map.map[i][j + 1] == '\0' && game->map.map[i][j] != '1')
				return (write(2, "Error\n invalid map wall", 23), 0);
			j++;
		}
	}
	return (1);
}

int	ft_vmapwall_space(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	//checker pour la premiere (en dessous) et la derniere ligne (au dessus) separement puis checker pour les lignes dedans
}

int	ft_vmapwall(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map.map[1][++j] != '\0')
	{
		if (game->map.map[1][j] != ' ' && game->map.map[1][j] != '1')
			return (write(2, "Error\n invalid map wall", 23), 0);
	}
	i = 0;
	j = 0;
	if (ft_vmapwall_2(game, i, j) == 0)
		return (0);
	while (game->map.map[i + 1] != NULL)
		i++;
	while (game->map.map[i + 1][j] != '\0')
	{
		if (game->map.map[i + 1][j] != ' ' && game->map.map[i + 1][j] != '1')
			return (write(2, "Error\n invalid map wall", 23), 0);
		j++;
	}
	if (ft_vmapwall_space(game) == 0)
		return (0);
	return (1);
}

int	ft_parsingmap(t_game *game)
{
	if (ft_vmapinput(game) == 0)
		return (0);
	if (ft_vmapspacecut(game) == 0)
		return (0);
	if (ft_vmapwall(game) == 0)
		return (0);
	return (1);
}
