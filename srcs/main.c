/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:22:34 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/25 14:38:18 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	ft_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len -1] == 'b' && str[len - 2] == 'u'
		&& str[len - 3] == 'c' && str[len - 4] == '.')
		return (1);
	write(2, "Error\n invalid file form (.cub expected)", 40);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && ft_cub(argv[1]) == 1)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
			return (0);
		if (ft_init_game(game, argv[1]) == 0)
		{
			write(2, "Error\n open error", 17);
			free(game);
			return (0);
		}
		if (ft_parsing(game) == 0)
			return (free(game), 0);
		if (ft_execgame(game) == 0)
			return (free(game), 0);
		ft_freeall(game);
		free(game);
	}
}
