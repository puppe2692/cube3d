/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:51:04 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/10 17:42:37 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_init_value(t_game *game)
{
	game->plan.x = 0;
	game->plan.y = 0.66;
	game->time.time = 0;
	game->time.oldtime = 0;
	game->res.x = 1280;
	game->res.y = 720;
}

void	ft_rendermap(t_game *game)
{
	int	x;

	x = -1;
	while (++x < game->res.x)
	{
		game->camerax = 2 * x / (double)game->res.x - 1;
		game->raydir.x = game->dir.x + game->plan.x * game->camerax;
		game->raydir.y = game->dir.y + game->plan.y * game->camerax;
		game->mapbox.x = game->plpos.x;
		game->mapbox.y = game->plpos.y;
	}
}

int	ft_execgame(t_game *game)
{
	ft_init_value(game)

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
	mlx_loop_hook(game->mlx, &ft_render, game);
	mlx_loop(game->mlx);
	ft_destroy_image(game);
	return (1);
}