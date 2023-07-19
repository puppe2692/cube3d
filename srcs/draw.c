/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:38:37 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/19 16:26:40 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_wall_setting(t_game *game)
{
	game->draw.drawstart = -game->draw.lineheight / 2 + game->res.y / 2;
	if (game->draw.drawstart < 0)
		game->draw.drawstart = 0;
	if (game->draw.drawstart >= game->res.y)
		game->draw.drawstart = game->res.y - 1;
	game->draw.drawend = game->draw.lineheight / 2 + game->res.y / 2;
	if (game->draw.drawend < 0)
		game->draw.drawend = 0;
	if (game->draw.drawend >= game->res.y)
		game->draw.drawend = game->res.y - 1;
}

void	ft_texture_to_render(t_game *game)
{
	if (game->side == 0)
	{
		if (game->raydir.x > 0)
			game->wall.texture_to_render = game->wall.w;
		else
			game->wall.texture_to_render = game->wall.e;
	}
	else
	{
		if (game->raydir.y > 0)
			game->wall.texture_to_render = game->wall.n;
		else
			game->wall.texture_to_render = game->wall.s;
	}
}

void	ft_draw(t_game *game, int x)
{
	game->draw.lineheight = (int)(game->res.y / game->perpwalldist);
	ft_wall_setting(game);
	ft_texture_to_render(game);
	if (game->side == 0)
	{
		if (game->raydir.x > 0)
			ft_render_line(game, x);
		else
			ft_render_line(game, x);
	}
	else
	{
		if (game->raydir.y > 0)
			ft_render_line(game, x);
		else
			ft_render_line(game, x);
	}
}
