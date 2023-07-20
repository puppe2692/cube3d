/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:14:12 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/20 11:56:46 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_init_dir(t_game *game, double x, double y)
{
	game->dir.x = x;
	game->dir.y = y;
}

void	ft_init_plan(t_game *game, double x, double y)
{
	game->plan.x = x;
	game->plan.y = y;
}

int	ft_closespace(t_game *game, int i, int j)
{
	if (i != 0 && game->map.map[i - 1][j] != ' '
		&& game->map.map[i - 1][j] != '1')
		return (0);
	else if (i != game->map.haut - 1 && game->map.map[i + 1][j] != ' '
		&& game->map.map[i + 1][j] != '1')
		return (0);
	else if (j != 0 && game->map.map[i][j - 1] != ' '
		&& game->map.map[i][j - 1] != '1')
		return (0);
	else if (j != game->map.larg - 1 && game->map.map[i][j + 1] != ' '
		&& game->map.map[i][j + 1] != '1')
		return (0);
	else
		return (1);
}

int	ft_vmapwall_space(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map[++i] != NULL)
	{
		j = -1;
		while (game->map.map[i][++j] != '\0')
		{
			if (game->map.map[i][j] == ' ')
			{
				if (ft_closespace(game, i, j) == 0)
					return (write(2, "Error\n invalid map space", 24), 0);
			}
		}
	}
	return (1);
}
