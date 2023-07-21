/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:36:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/21 13:31:59 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_mapsize(char *str)
{
	int		size;
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

char	**ft_readmap(t_game *game, char *str)
{
	int		fd;
	char	**newmap;
	int		i;

	game->inputsize = ft_mapsize(str);
	if (game->inputsize == -1)
		return (NULL);
	newmap = malloc((game->inputsize + 1) * sizeof(char *));
	if (!newmap)
		return (NULL);
	newmap[game->inputsize] = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < game->inputsize)
	{
		newmap[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (newmap);
}

char	*ft_findinput(t_game *game, char *str)
{
	int		i;
	int		dblcheck;
	char	*tmp;

	i = 0;
	dblcheck = 0;
	tmp = NULL;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
	{
		if (!strncmp(game->input[i], str, ft_strlen(str)))
		{
			game->vinputnbr++;
			dblcheck++;
			tmp = game->input[i];
		}
		i++;
	}
	if (dblcheck != 1)
		return (NULL);
	return (tmp);
}

int	ft_init_game(t_game *game, char *str)
{
	game->input = ft_readmap(game, str);
	if (game->input == NULL)
		return (0);
	game->vinputnbr = 0;
	game->wall.no = ft_findinput(game, "NO ");
	game->wall.so = ft_findinput(game, "SO ");
	game->wall.we = ft_findinput(game, "WE ");
	game->wall.ea = ft_findinput(game, "EA ");
	game->floor = ft_findinput(game, "F ");
	game->roof = ft_findinput(game, "C ");
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_dblstrfree(game->input, ft_mapsize(str)), 0);
	game->map.map = ft_init_map(game);
	if (!game->map.map)
		return (0);
	game->wall.n = NULL;
	game->wall.s = NULL;
	game->wall.w = NULL;
	game->wall.e = NULL;
	game->fcol = NULL;
	game->rcol = NULL;
	game->dstr = 0;
	game->bool = 1;
	return (1);
}
