/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:46 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/27 14:41:32 by nwyseur          ###   ########.fr       */
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
