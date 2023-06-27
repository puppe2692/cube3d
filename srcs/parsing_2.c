/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:46 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/27 15:45:45 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

void	ft_convertdir(t_game *game)
{
	char	*tmp;

	tmp = game->wall.no;
	game->wall.no = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	free (tmp);
	tmp = game->wall.so;
	game->wall.so = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	free (tmp);
	tmp = game->wall.we;
	game->wall.we = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	free (tmp);
	tmp = game->wall.ea;
	game->wall.ea = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	free (tmp);
}

int	ft_vcolor_suite(char **hex)
{
	int	i;
	int	j;

	i = 0;
	while (hex[i] != NULL)
		i++;
	if (i != 3)
		return (0);
	i = -1;
	while (hex[i++] != NULL)
	{
		j = 0;
		while (hex[i][j] != '\0' || hex[i][j] != '\n')
		{
			if (hex[i][j] < 48 || hex[i][j] > 57)
				return (0);
			j++;
		}
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
	if (ft_vcolor_suite(game->fcol) == 0 || ft_vcolor_suite(game->rcol) == 0)
	{
		write(2, "Error\n color format", 19);
		return (0);
	}
	while (i < 3)
	{
		j = ft_atoi(game->fcol[i]);
		k = ft_atoi(game->rcol[i]);
		if (j < 0 || j > 255 || i < 0 || i > 255
			|| game->rcol[i] == NULL || game->fcol[i] == NULL)
		{
			write(2, "Error\n color format", 19);
			return (0);
		}
		i++;
	}
	return (1);
}
