/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_casting_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:06:37 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/25 14:22:41 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_init_value(t_game *game)
{
	game->time.time = 0;
	game->time.oldtime = 0;
	game->res.x = 1280;
	game->res.y = 720;
	game->speed.frametime = (double)(60) / (double)(1000);
	game->speed.movespeed = game->speed.frametime * 5;
	game->speed.rotspeed = game->speed.frametime * 3;
}

void	ft_init_ray(t_game *game, int x)
{
	game->camerax = 2 * x / (double)game->res.x - 1;
	game->raydir.x = game->dir.x + game->plan.x * game->camerax;
	game->raydir.y = game->dir.y + game->plan.y * game->camerax;
	game->mapbox.x = (int)game->plpos.x;
	game->mapbox.y = (int)game->plpos.y;
}

void	ft_init_deltadist(t_game *game)
{
	if (game->raydir.x == 0)
		game->deltadist.x = 1e30;
	else
		game->deltadist.x = fabs(1 / game->raydir.x);
	if (game->raydir.y == 0)
		game->deltadist.y = 1e30;
	else
		game->deltadist.y = fabs(1 / game->raydir.y);
	game->hit = 0;
}

void	ft_init_step(t_game *game)
{
	if (game->raydir.x < 0)
		game->step.x = -1;
	else
		game->step.x = 1;
	if (game->raydir.y < 0)
		game->step.y = -1;
	else
		game->step.y = 1;
}

void	ft_init_sidedist(t_game *game)
{
	int	coord_x;
	int	coord_y;

	coord_x = floor(game->plpos.x);
	coord_y = floor(game->plpos.y);
	if (game->raydir.x < 0)
		game->sidedist.x = (game->plpos.x - coord_x) * game->deltadist.x;
	else
	{
		game->sidedist.x = (coord_x + 1.0 - game->plpos.x)
			* game->deltadist.x;
	}
	if (game->raydir.y < 0)
		game->sidedist.y = (game->plpos.y - coord_y) * game->deltadist.y;
	else
	{
		game->sidedist.y = (coord_y + 1.0 - game->plpos.y)
			* game->deltadist.y;
	}
}
