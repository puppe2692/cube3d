/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:09:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/25 17:49:01 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_init_ppos(t_game *game, int *pers, int i, int j)
{
	pers[0]++;
	game->plpos.x = (double)j + 0.5;
	game->plpos.y = (double)i + 0.5;
	if (game->map.map[i][j] == 'N')
	{
		ft_init_dir(game, 0, -1);
		ft_init_plan(game, PLAN, 0);
	}
	else if (game->map.map[i][j] == 'S')
	{
		ft_init_dir(game, 0, 1);
		ft_init_plan(game, -PLAN, 0);
	}
	else if (game->map.map[i][j] == 'E')
	{
		ft_init_dir(game, 1, 0);
		ft_init_plan(game, 0, PLAN);
	}
	else if (game->map.map[i][j] == 'W')
	{
		ft_init_dir(game, -1, 0);
		ft_init_plan(game, 0, -PLAN);
	}
}

int	ft_vmapinput(t_game *game, int i)
{
	int	j;
	int	pers;

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
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
				|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
				ft_init_ppos(game, &pers, i, j);
			if (pers > 1)
				return (write(2, "Error\n too many players", 23), 0);
		}
	}
	if (pers == 0)
		return (write(2, "Error\n player is missing", 24), 0);
	return (1);
}

int	ft_vmapwall_2(t_game *game, int i, int j)
{
	while (game->map.map[++i + 2] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] == ' ')
			j++;
		if (game->map.map[i][j] != '1')
			return (write(2, "Error\n 1 invalid map wall", 25), 0);
		while (game->map.map[i][j] != '\0')
		{
			if ((game->map.map[i - 1][j] == ' '
				|| game->map.map[i - 1][j] == '\0'
				|| game->map.map[i + 1][j] == ' '
				|| game->map.map[i + 1][j] == '\0')
				&& game->map.map[i][j] != '1' && game->map.map[i][j] != ' ')
				return (write(2, "Error\n 2 invalid map wall", 25), 0);
			if (game->map.map[i][j + 1] == '\0' && game->map.map[i][j] != '1')
				return (write(2, "Error\n 3 invalid map wall", 25), 0);
			j++;
		}
	}
	return (1);
}

int	ft_vmapwall(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map.map[0][++j] != '\0')
	{
		if (game->map.map[0][j] != ' ' && game->map.map[0][j] != '1')
			return (write(2, "Error\n 4 invalid map wall", 25), 0);
	}
	i = 0;
	j = 0;
	if (ft_vmapwall_2(game, i, j) == 0)
		return (0);
	while (game->map.map[i + 1] != NULL)
		i++;
	while (game->map.map[i][j] != '\0')
	{
		if (game->map.map[i][j] != ' ' && game->map.map[i][j] != '1')
			return (write(2, "Error\n 5 invalid map wall", 25), 0);
		j++;
	}
	if (ft_vmapwall_space(game) == 0)
		return (0);
	return (1);
}

int	ft_parsingmap(t_game *game)
{
	if (ft_vmapinput(game, -1) == 0)
		return (ft_freeall(game), 0);
	if (ft_vmapwall(game) == 0)
		return (ft_freeall(game), 0);
	return (1);
}
