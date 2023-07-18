/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:51:04 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/18 12:58:09 by nwyseur          ###   ########.fr       */
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

void	ft_init_value(t_game *game)
{
	game->plan.x = 0;
	game->plan.y = 0.66;
	game->time.time = 0;
	game->time.oldtime = 0;
	game->res.x = 640;
	game->res.y = 480;
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

void	ft_launchray(t_game *game)
{
	while(game->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (game->sidedist.x < game->sidedist.y)
		{
			printf("--BONJOUR--\n");
			game->sidedist.x += game->deltadist.x;
			game->mapbox.x += game->step.x;
			game->side = 0;
		}
		else
		{
			printf("??AUREVOIR??\n");
			game->sidedist.y += game->deltadist.y;
			game->mapbox.y += game->step.y;
			game->side = 1;
		}
		//Check if ray has hit a wall
		printf("PLPOS x: %f\n", game->plpos.x);
		printf("PLPOS y: %f\n", game->plpos.y);
		printf("ICI x: %i\n", game->mapbox.x);
		printf("LA y: %i\n", game->mapbox.y);
		if (ft_map_limits(game, game->mapbox.x, game->mapbox.y) == 1)
		{
			printf("---------------");
			printf("valeur x: %i\n", game->map.map[game->mapbox.y][game->mapbox.x]);
			printf("---------------");
			game->hit = 1;
		}
	}
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
		if (game->side == 0)
		{
			game->perpwalldist = (game->sidedist.x - game->deltadist.x);
			game->texture.x = game->mapbox.y + game->perpwalldist
				* game->raydir.y;
		}
		else
		{
			game->perpwalldist = (game->sidedist.y - game->deltadist.y);
			game->texture.x = game->mapbox.x + game->perpwalldist
				* game->raydir.x; // ici
		}
		game->texture.x -= floor(game->texture.x); // ici
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
	printf("LATUILE\n");
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &ft_handle_d, game);
	mlx_loop_hook(game->mlx, &ft_rendermap, game);
	mlx_loop(game->mlx);
	//ft_destroy_image(game);
	return (1);
}