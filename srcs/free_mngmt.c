/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mngmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:37 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/19 16:45:47 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_handle_d(t_game *game)
{
	game->dstr = 1;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	// ici ft_destroy_image(game);
	// ici ft_freeall(game);
	exit(1);
}
