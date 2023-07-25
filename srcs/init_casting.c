/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:51:04 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/25 18:12:19 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_map_limits(t_game *game, double x, double y)
{
	int	x_round;
	int	y_round;

	x_round = (int) x;
	y_round = (int) y;
	if (y_round < 0 || y_round >= game->map.haut
		|| x_round < 0 || x_round >= (int) ft_strlen(game->map.map[y_round])
		|| game->map.map[y_round][x_round] == ' '
		|| game->map.map[y_round][x_round] == '1')
	{
		return (1);
	}
	return (0);
}

void	ft_launchray(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->sidedist.x < game->sidedist.y)
		{
			game->sidedist.x += game->deltadist.x;
			game->mapbox.x += game->step.x;
			game->side = 0;
		}
		else
		{
			game->sidedist.y += game->deltadist.y;
			game->mapbox.y += game->step.y;
			game->side = 1;
		}
		if (ft_map_limits(game, game->mapbox.x, game->mapbox.y) == 1)
			game->hit = 1;
	}
}

void	ft_walldist(t_game *game)
{
	if (game->side == 0)
	{
		game->perpwalldist = (game->sidedist.x - game->deltadist.x);
		game->texture.x = game->plpos.y + game->perpwalldist
			* game->raydir.y;
	}
	else
	{
		game->perpwalldist = (game->sidedist.y - game->deltadist.y);
		game->texture.x = game->plpos.x + game->perpwalldist
			* game->raydir.x;
	}
	game->texture.x -= floor(game->texture.x);
}

int	ft_rendermap(t_game *game)
{
	int	x;

	x = -1;
	if (game->bool == 0)
		return (0);
	while (++x < game->res.x)
	{
		ft_init_ray(game, x);
		ft_init_deltadist(game);
		ft_init_sidedist(game);
		ft_init_step(game);
		ft_launchray(game);
		ft_walldist(game);
		ft_draw(game, x);
	}
	game->bool = 0;
	return (1);
}

int	ft_execgame(t_game *game)
{
	ft_init_value(game);
	game->win = mlx_new_window(game->mlx, game->res.x,
			game->res.y, "Le sang de tes morts Didier!");
	if (game->win == NULL)
	{
		free(game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	ft_rendermap(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &ft_handle_d, game);
	mlx_loop_hook(game->mlx, &ft_rendermap, game);
	mlx_loop(game->mlx);
	return (1);
}
