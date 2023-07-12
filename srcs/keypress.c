/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:24 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/12 17:35:38 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"


int	ft_handle_d(t_game *game)
{
	game->dstr = 1;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	//ft_destroy_image(game);
	//ft_freeall(game);
	exit(1);
}

void	ft_handle_cammvt(int keysym, t_game *game)
{
	double	olddirx;
	double	oldplanex;

	if (keysym == XK_Right)
	{
		//both camera direction and camera plane must be rotated
		olddirx = game->dir.x;
		game->dir.x = game->dir.x * cos(-game->speed.rotspeed) - game->dir.y * sin(-game->speed.rotspeed);
		game->dir.y = olddirx * sin(-game->speed.rotspeed) + game->dir.y * cos(-game->speed.rotspeed);
		oldplanex = game->plan.x;
		game->plan.x = game->plan.x * cos(-game->speed.rotspeed) - game->plan.y * sin(-game->speed.rotspeed);
		game->plan.y = oldplanex * sin(-game->speed.rotspeed) + game->plan.y * cos(-game->speed.rotspeed);
	}
	//rotate to the left
	if (keysym == XK_Left)
	{
		//both camera direction and camera plane must be rotated
		olddirx = game->dir.x;
		game->dir.x = game->dir.x * cos(game->speed.rotspeed) - game->dir.y * sin(game->speed.rotspeed);
		game->dir.y = olddirx * sin(game->speed.rotspeed) + game->dir.y * cos(game->speed.rotspeed);
		oldplanex = game->plan.x;
		game->plan.x = game->plan.x * cos(game->speed.rotspeed) - game->plan.y * sin(game->speed.rotspeed);
		game->plan.y = oldplanex * sin(game->speed.rotspeed) + game->plan.y * cos(game->speed.rotspeed);
	}
}

void	ft_handle_keymvt(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->dir.x * game->speed.movespeed)] == 0) 
			game->plpos.x += game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->dir.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y += game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_s)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x - game->dir.x * game->speed.movespeed)] == 0) 
			game->plpos.x -= game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y - game->dir.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y -= game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_a)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->plan.x * game->speed.movespeed)] == 0) 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->plan.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
	if (keysym == XK_d)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->plan.x * game->speed.movespeed)] == 0) 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->plan.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
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
		printf("POSITION x : %f\n", game->plpos.x);
		printf("POSITION y : %f\n", game->plpos.y);
	}
	if (keysym == XK_Left || keysym == XK_Right)
	{
		ft_handle_cammvt(keysym, game);
		game->bool = 1;
	}
	return (0);
}