/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:24 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/25 18:29:38 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_rot(t_game *game, double rotspeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->dir.x;
	game->dir.x = game->dir.x * cos(rotspeed)
		- game->dir.y * sin(rotspeed);
	game->dir.y = olddirx * sin(rotspeed)
		+ game->dir.y * cos(rotspeed);
	oldplanex = game->plan.x;
	game->plan.x = game->plan.x * cos(rotspeed)
		- game->plan.y * sin(rotspeed);
	game->plan.y = oldplanex * sin(rotspeed)
		+ game->plan.y * cos(rotspeed);
}

void	ft_mvt(t_game *game, double axex, double axey, int keysym)
{
	if (keysym == XK_w || keysym == XK_d)
	{
		if (game->map.map[(int)(game->plpos.y)]
			[(int)(game->plpos.x + axex * game->speed.movespeed)] != '1')
			game->plpos.x = game->plpos.x + axex * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + axey * game->speed.movespeed)]
			[(int)(game->plpos.x)] != '1')
			game->plpos.y = game->plpos.y + axey * game->speed.movespeed;
	}
}

void	ft_handle_cammvt(int keysym, t_game *game)
{
	if (keysym == XK_Left)
	{
		ft_rot(game, -game->speed.rotspeed);
	}
	if (keysym == XK_Right)
	{
		ft_rot(game, game->speed.rotspeed);
	}
}

void	ft_handle_keymvt(int keysym, t_game *game)
{
	if (keysym == XK_w)
		ft_mvt(game, game->dir.x, game->dir.y, keysym);
	if (keysym == XK_s)
	{
		if (game->map.map[(int)(game->plpos.y)]
			[(int)(game->plpos.x - game->dir.x * game->speed.movespeed)] != '1')
			game->plpos.x -= game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y - game->dir.y
				* game->speed.movespeed)][(int)(game->plpos.x)] != '1')
			game->plpos.y -= game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_a)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x
			- game->plan.x * game->speed.movespeed)] != '1')
			game->plpos.x -= game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y - game->plan.y
				* game->speed.movespeed)][(int)(game->plpos.x)] != '1')
			game->plpos.y -= game->plan.y * game->speed.movespeed;
	}
	if (keysym == XK_d)
		ft_mvt(game, game->plan.x, game->plan.y, keysym);
}

int	ft_handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_handle_d(game);
	if (keysym == XK_w || keysym == XK_s
		|| keysym == XK_a || keysym == XK_d)
	{
		ft_handle_keymvt(keysym, game);
		game->bool = 1;
	}
	if (keysym == XK_Left || keysym == XK_Right)
	{
		ft_handle_cammvt(keysym, game);
		game->bool = 1;
	}
	return (0);
}
