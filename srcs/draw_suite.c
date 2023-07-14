/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:16:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/14 12:47:34 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_data_init(t_game *game, double *data)
{
	game->texture.x *= game->wall.texture_to_render->width;
	data[0] = 1.0 * game->wall.texture_to_render->height
		/ (game->res.y / game->perpwalldist); // ici
	data[1] = (game->draw.drawstart - game->res.y / 2
			+ (game->res.y / game->perpwalldist) / 2) * data[0];
}

void	ft_render_line(t_game *game, int x)
{
	double	data[3];


}