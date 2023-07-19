/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testparsingspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:53:35 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/19 16:29:51 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_vmapwall_space(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	
	//checker pour la premiere (en dessous) et la derniere ligne (au dessus) separement puis checker pour les lignes dedans
}

int	ft_istofill(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '0' || c == 'Q')
		return (1);
	return (0);
}

void	ft_walk(char **map, t_pos size, t_pos cur, int *count)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| ft_istofill(map[cur.y][cur.x]) == 0)
		return ;
	if (map[cur.y][cur.x] == 'C')
		count->c++;
	if (map[cur.y][cur.x] == 'E')
		count->e++;
	map[cur.y][cur.x] = 'X';
	ft_walk(map, size, (t_pos){cur.x - 1, cur.y}, count);
	ft_walk(map, size, (t_pos){cur.x + 1, cur.y}, count);
	ft_walk(map, size, (t_pos){cur.x, cur.y - 1}, count);
	ft_walk(map, size, (t_pos){cur.x, cur.y + 1}, count);
}

void	ft_findspace(t_game *game, char **map2, int *bound, t_pos size)
{
	int		i;
	int		j;
	t_pos	cur;

	i = -1;
	j = -1;
	while (map2[++i][0] != NULL)
	{
		if (map2[i][0] == ' ')
		{
			cur.x = 0;
			cur.y = i;
			ft_walk(map2, size, cur, bound);
		}
	}
	while (map2[0][++j] != '\0')
	{
		if (map2[0][j] == ' ')
		{
			cur.x = j;
			cur.y = 0;
			ft_walk(map2, size, cur, bound);
		}
	}
}

int	ft_vpath(t_game *game)
{
	int		bound;
	char	**map2;
	t_pos	size;

	bound = 0;
	size.x = game->map.larg;
	size.y = game->map.haut;
	map2 = ft_init_map(game);
	if (!map2)
		return (0);
	ft_findspace(game, map2, &bound, size);
	while (++i < size.y)
		free(map2[i]);
	free(map2);
	if (bound > 0)
		return (0);
	return (1);
}
