/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:09:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/30 14:58:09 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_vmapinput(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map[++i] != NULL)
	{
		j = -1;
		while (game->map.map[i][++j] != '\0')
		{
			if (game->map.map[i][j] != ' ' && game->map.map[i][j] != '1'
				&& game->map.map[i][j] != '0' && game->map.map[i][j] != ' '
				&& game->map.map[i][j] != '1' && game->map.map[i][j] != '0'
				&& game->map.map[i][j] != ' ')
				return (write(2, "Error\n invalid map input", 24), 0);
		}
	}
}

int	ft_parsingmap(t_game *game)
{
	if (ft_vmapinput(game) == 0)
		return (0);
}
