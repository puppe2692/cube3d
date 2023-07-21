/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mngmt_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:45:21 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/21 12:51:48 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_destroy_image(t_game *game)
{
	if (game->wall.n != NULL)
		mlx_destroy_image(game->mlx, game->wall.n);
	if (game->wall.s != NULL)
		mlx_destroy_image(game->mlx, game->wall.s);
	if (game->wall.e != NULL)
		mlx_destroy_image(game->mlx, game->wall.e);
	if (game->wall.w != NULL)
		mlx_destroy_image(game->mlx, game->wall.w);
}

void	ft_freedir(t_game *game)
{
	if (game->wall.no != NULL)
		free(game->wall.no);
	if (game->wall.so != NULL)
		free(game->wall.so);
	if (game->wall.ea != NULL)
		free(game->wall.ea);
	if (game->wall.we != NULL)
		free(game->wall.we);
	game->wall.no = NULL;
	game->wall.so = NULL;
	game->wall.ea = NULL;
	game->wall.we = NULL;
}

void	ft_freecol(t_game *game)
{
	if (game->floor != NULL)
		free(game->floor);
	if (game->roof != NULL)
		free(game->roof);
	game->floor = NULL;
	game->roof = NULL;
}

void	ft_dblstrfree(char **sstr, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(sstr[i]);
		sstr[i] = NULL;
		i++;
	}
	free(sstr);
	sstr = NULL;
}

void	ft_freesplit(char **sstr)
{
	int	i;

	i = 0;
	while (sstr[i] != NULL)
		i++;
	ft_dblstrfree(sstr, i);
}
