/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:16:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/21 12:52:29 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_get_rgb_color(char **color)
{
	return ((ft_atoi(color[0]) << 16)
		+ (ft_atoi(color[1]) << 8) + ft_atoi(color[2]));
}

int	ft_get_pix_color(t_game *game)
{
	int				offset;
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	offset = (int) game->texture.y * game->wall.texture_to_render->size_line
		+ (int) game->texture.x * (game->wall.texture_to_render->bpp / 8);
	b = game->wall.texture_to_render->data[offset];
	g = game->wall.texture_to_render->data[offset + 1];
	r = game->wall.texture_to_render->data[offset + 2];
	return ((r << 16) + (g << 8) + b);
}

void	ft_data_init(t_game *game, double *data)
{
	game->texture.x *= game->wall.texture_to_render->width;
	data[0] = 1.0 * game->wall.texture_to_render->height
		/ (game->res.y / game->perpwalldist);
	data[1] = (game->draw.drawstart - game->res.y / 2
			+ (game->res.y / game->perpwalldist) / 2) * data[0];
}

void	ft_render_line(t_game *game, int x)
{
	double	data[2];
	int		j;

	ft_data_init(game, data);
	j = 0;
	while (j < game->res.y)
	{
		if (j < game->draw.drawstart)
			mlx_pixel_put(game->mlx, game->win, x, j,
				ft_get_rgb_color(game->rcol));
		else if (j < game->draw.drawend)
		{
			if (data[1] >= game->wall.texture_to_render->height)
				game->texture.y = game->wall.texture_to_render->height - 1;
			else
				game->texture.y = data[1];
			data[1] += data[0];
			mlx_pixel_put(game->mlx, game->win, x, j,
				ft_get_pix_color(game));
		}
		else
			mlx_pixel_put(game->mlx, game->win, x, j,
				ft_get_rgb_color(game->fcol));
		j++;
	}
}
