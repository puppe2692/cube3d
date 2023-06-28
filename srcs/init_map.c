/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:43:24 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/28 18:55:32 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_hautlarg(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
			i++;
	while (game->input[j] != NULL)
		j++;
	game->map.haut = j;
	game->map.larg = 0;
	while (game->input[i] != NULL)
	{
		len = ft_strlen(game->input[i]);
		if (len > game->map.larg)
			game->map.larg = len;
		i++;
	}
}

int	ft_mapmalloc(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->map.map = malloc((game->map.haut + 1) * sizeof(char *));
	if (!game->map.map)
		return (0);
	game->map.map[game->map.haut] = NULL;
	while (game->map.map[++i] != NULL)
	{
		game->map.map[i] = malloc((game->map.larg + 1) * sizeof(char));
		if (!game->map.map[i])
		return (0); // free management return (free de ce qui est creer + 0)
		game->map.map[i][game->map.larg] = '\0';
	}
	i = -1;
	while (game->map.map[++i] != NULL)
	{
		j = -1;
		while (game->map.map[i][++j] != '\0')
			game->map.map[i][j] = '\0';
	}
	return (1);
}

void	ft_mapcopy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
			i++;
	j = 0;
	while (game->input[i] != NULL)
	{
		game->map.map[j] = game->input[i];
		i++;
		j++;
	}
}

int	ft_init_map(t_game *game)
{
	ft_hautlarg(game);
	if (ft_mapmalloc(game) == 0)
		return (0);
	ft_mapcopy(game);
	return (1);
}
