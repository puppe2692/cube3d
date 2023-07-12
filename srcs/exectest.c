/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:51:04 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/12 15:20:36 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_init_value(t_game *game)
{
	game->plan.x = 0;
	game->plan.y = 0.66;
	game->time.time = 0;
	game->time.oldtime = 0;
	game->res.x = 640;
	game->res.y = 480;
	game->speed.frametime = 33 / 1000;
	game->speed.movespeed = game->speed.frametime * 5;
	game->speed.rotspeed = game->speed.frametime * 3;
}

void	ft_init_ray(t_game *game, int x)
{
	game->camerax = 2 * x / (double)game->res.x - 1;
	game->raydir.x = game->dir.x + game->plan.x * game->camerax;
	game->raydir.y = game->dir.y + game->plan.y * game->camerax;
	game->mapbox.x = game->plpos.x;
	game->mapbox.y = game->plpos.y;
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

void	ft_init_sidedist(t_game *game)
{
	if (game->raydir.x < 0)
	{
		game->step.x = -1;
		game->sidedist.x = (game->plpos.x - game->mapbox.x) * game->deltadist.x;
	}
	else
	{
		game->step.x = 1;
		game->sidedist.x = (game->mapbox.x + 1.0 - game->plpos.x)
			* game->deltadist.x;
	}
	if (game->raydir.y < 0)
	{
		game->step.y = -1;
		game->sidedist.y = (game->plpos.y - game->mapbox.y) * game->deltadist.y;
	}
	else
	{
		game->step.y = 1;
		game->sidedist.y = (game->mapbox.y + 1.0 - game->plpos.y)
			* game->deltadist.y;
	}
}

void	ft_color(t_game *game, int x)
{
	int	j;

	if (game->map.map[game->mapbox.x][game->mapbox.y] == 1)
		game->draw.color = 0xFF00;
	if (game->side == 1)
		game->draw.color = game->draw.color / 2;
	j = game->draw.drawstart;
	while (j < game->draw.drawend)
	{
		mlx_pixel_put(game->mlx, game->win, x, j, game->draw.color);
		j++;
	}
}

void	ft_draw(t_game *game, int x)
{
	game->draw.lineheight = (int)(game->res.y / game->perpwalldist);
	game->draw.drawstart = -game->draw.lineheight / 2 + game->res.y / 2;
	if (game->draw.drawstart < 0)
		game->draw.drawstart = 0;
	game->draw.drawend = game->draw.lineheight / 2 + game->res.y / 2;
	if (game->draw.drawend >= game->res.y)
		game->draw.drawend = game->res.y - 1;
	ft_color(game, x);
}

void	ft_rendermap(t_game *game)
{
	int	x;

	x = -1;
	if (game->bool == 0)
		return;
	while (++x < game->res.x)
	{
		ft_init_ray(game, x);
		ft_init_sidedist(game);
		while(game->hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
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
			//Check if ray has hit a wall
			if (game->map.map[game->mapbox.x][game->mapbox.y] == 1)
				game->hit = 1;
		}
		if (game->side == 0)
			game->perpwalldist = (game->sidedist.x - game->deltadist.x);
		else
			game->perpwalldist = (game->sidedist.y - game->deltadist.y);
		ft_draw(game, x);
	}
	game->bool = 0;
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
	//ft_destroy_image(game);
	return (1);
}