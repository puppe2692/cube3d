/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:24 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/11 16:15:33 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_handle_d(game);
	if (keysym == XK_w || keysym == XK_s
		|| keysym == XK_a || keysym == XK_d)
		ft_handle_keymvt(keysym, game);
	if (keysym == XK_Left || keysym == XK_Right)
		ft_handle_cammvt(keysym, game);
	return (0);
}

int	ft_handle_d(t_game *game)
{
	game->dstr = 1;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	ft_destroy_image(game);
	//ft_freeall(game);
	exit(1);
}

// void	ft_handle_cammvt(int keysym, t_game *game)

/* void	ft_pimvt(t_game *game, int keysym, int x, int y)
{
	if (keysym == XK_w)
		mlx_put_image_to_window(game->mlx, game->win, game->alien[0],
			x * 32, y * 32);
	if (keysym == XK_s)
		mlx_put_image_to_window(game->mlx, game->win, game->alien[1],
			x * 32, y * 32);
	if (keysym == XK_a)
		mlx_put_image_to_window(game->mlx, game->win, game->alien[3],
			x * 32, y * 32);
	if (keysym == XK_d)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->alien[6],
			x * 32 - 24, y * 32);
		mlx_put_image_to_window(game->mlx, game->win, game->alien[2],
			x * 32 - 16, y * 32);
		mlx_put_image_to_window(game->mlx, game->win, game->alien[10],
			x * 32 - 8, y * 32);
		mlx_put_image_to_window(game->mlx, game->win, game->alien[2],
			x * 32, y * 32);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->sf,
		game->ppx * 32, game->ppy * 32);
}

int	ft_handle_keymvt(int keysym, t_game *game)
{
	if (keysym == XK_w && ft_mvtcond(game, game->ppy - 1, game->ppx) == 1)
	{
		ft_pimvt(game, keysym, game->ppx, (game->ppy - 1));
		game->ppy--;
	}
	if (keysym == XK_s && ft_mvtcond(game, game->ppy + 1, game->ppx) == 1)
	{
		ft_pimvt(game, keysym, game->ppx, (game->ppy + 1));
		game->ppy++;
	}
	if (keysym == XK_a && ft_mvtcond(game, game->ppy, game->ppx - 1) == 1)
	{
		ft_pimvt(game, keysym, (game->ppx - 1), game->ppy);
		game->ppx--;
	}
	if (keysym == XK_d && ft_mvtcond(game, game->ppy, game->ppx + 1) == 1)
	{
		ft_pimvt(game, keysym, (game->ppx + 1), game->ppy);
		game->ppx++;
	}
	if ((game->map[game->ppy][game->ppx] == 'E' && game->nb_cc == game->collec)
		|| (game->ppy == game->e.y && game->ppx == game->e.x))
		ft_handle_d(game);
	return (0);
}
*/