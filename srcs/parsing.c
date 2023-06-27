/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:00:19 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/27 14:41:43 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_vwronginput(t_game *game)
{
	int	i;

	i = 0;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
	{
		if (strncmp(game->input[i], "NO ", 3)
			&& strncmp(game->input[i], "SO ", 3)
			&& strncmp(game->input[i], "WE ", 3)
			&& strncmp(game->input[i], "EA ", 3)
			&& strncmp(game->input[i], "F ", 2)
			&& strncmp(game->input[i], "J ", 2)
			&& strncmp(game->input[i], "C ", 2)
			&& strncmp(game->input[i], "\n", 1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_vinput(t_game *game)
{
	if (ft_vwronginput(game) == 0)
	{
		write(2, "Error\n invalid input", 20);
		return (0);
	}
	if (game->vinputnbr != 6)
	{
		write(2, "Error\n input nbr of placement, ", 31);
		write(2, "verify you have the 6 correct ", 30);
		write(2, "inputs placed before the map\n", 29);
		return (0);
	}
	if (game->wall.no == NULL || game->wall.so == NULL || game->wall.we == NULL
		|| game->wall.ea == NULL || game->floor == NULL || game->roof == NULL)
	{
		write(2, "Error\n input in double\n", 23);
		return (0);
	}
	return (1);
}

int	ft_vimage(t_game *game)
{
	int	w;
	int	h;

	ft_convertdir(game);
	game->wall.n = mlx_xpm_file_to_image(game->mlx,
			game->wall.no, &w, &h);
	game->wall.s = mlx_xpm_file_to_image(game->mlx,
			game->wall.so, &w, &h);
	game->wall.e = mlx_xpm_file_to_image(game->mlx,
			game->wall.we, &w, &h);
	game->wall.w = mlx_xpm_file_to_image(game->mlx,
			game->wall.ea, &w, &h);
	if (game->wall.n == NULL || game->wall.s == NULL
		|| game->wall.e == NULL || game->wall.w == NULL)
	{
		write(2, "Error\n image upload", 19);
		return (0);
	}
	return (1);
}

int	ft_vcolor(t_game *game)
{
	int	i;
	int	j;
	int	k;

	game->fcol = ft_split(game->floor + 2, ',');
	game->rcol = ft_split(game->roof + 2, ',');
	i = 0;
	while (i < 3)
	{
		j = ft_atoi(game->fcol[i]);
		k = ft_atoi(game->rcol[i]);
		if (j < 0 || j > 255 || i < 0 || i > 255)
		{
			write(2, "Error\n color format", 19);
			return (0);
		}
		i++;
	}
	return (1);


}

int	ft_parsing(t_game *game)
{
	if (ft_vinput(game) == 0)
		return (0);
	if (ft_vimage(game) == 0)
		return (0);
	if (ft_vcolor(game) == 0)
		return (0);
	return (1);
}
