/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:36:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/26 14:01:19 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_includes.h"

int	ft_ber(char *str)
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
			ft_freepasall(game);
			return (0);
		}
		if (ft_parsing(game) == 0)
		{
			ft_freeall(game);
			return (0);
		}
		if (ft_game(game) == 0)
		{
			free(game);
			return (0);
		}
		ft_freeall(game);
	}
}
