/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:43:24 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/20 11:25:32 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_strlencube(const char *s)
{
	int32_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_hautlarg(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
			i++;
	while (game->input[j] != NULL)
		j++;
	game->map.haut = j - i;
	game->map.larg = 0;
	while (game->input[i] != NULL)
	{
		len = ft_strlencube(game->input[i]);
		if (len > game->map.larg)
			game->map.larg = len;
		i++;
	}
}

char	**ft_mapmalloc(t_game *game, char **new)
{
	int	i;
	int	j;

	i = -1;
	new = ft_calloc((game->map.haut + 1), sizeof(char *));
	if (!new)
		return (NULL);
	new[game->map.haut] = NULL;
	while (++i < game->map.haut)
	{
		new[i] = ft_calloc((game->map.larg + 1), sizeof(char));
		if (!new[i])
			return (ft_dblstrfree(new, i), NULL);
		new[i][game->map.larg] = '\0';
	}
	i = -1;
	while (new[++i] != NULL)
	{
		j = -1;
		while (new[i][++j] != '\0')
			new[i][j] = '\0';
	}
	return (new);
}

void	ft_mapcopy(t_game *game, char **new)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (game->input[i] != NULL && game->input[i][0] != ' '
			&& game->input[i][0] != '1' && game->input[i][0] != '0')
			i++;
	while (game->input[i] != NULL)
	{
		k = 0;
		while (game->input[i][k] && game->input[i][k] != '\n')
		{
			new[j][k] = game->input[i][k];
			k++;
		}
		i++;
		j++;
	}
}

char	**ft_init_map(t_game *game)
{
	char	**new;

	new = NULL;
	ft_hautlarg(game);
	new = ft_mapmalloc(game, new);
	if (!new)
		return (NULL);
	ft_mapcopy(game, new);
	return (new);
}
