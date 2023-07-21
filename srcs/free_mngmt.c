/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mngmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:37 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/21 12:46:15 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_freepasall(t_game *game, int i)
{
	ft_freesplit(game->input);
	ft_dblstrfree(game->map.map, game->map.haut);
	if (game->fcol != NULL)
		ft_freesplit(game->fcol);
	if (game->rcol != NULL)
		ft_freesplit(game->rcol);
	if (i != 2)
		ft_freedir(game);
	if (i != 1 && i != 2)
		ft_freecol(game);
	ft_destroy_image(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	ft_freeall(t_game *game)
{
	ft_freesplit(game->input);
	ft_dblstrfree(game->map.map, game->map.haut);
	if (game->fcol != NULL)
		ft_freesplit(game->fcol);
	if (game->rcol != NULL)
		ft_freesplit(game->rcol);
	ft_freedir(game);
	ft_freecol(game);
	ft_destroy_image(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	ft_handle_d(t_game *game)
{
	game->dstr = 1;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	ft_destroy_game(game);
	exit(0);
}

void	ft_destroy_game(t_game *game)
{
	ft_freeall(game);
	free(game);
}
