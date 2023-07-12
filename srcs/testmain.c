/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:22:34 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/12 16:00:40 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_includes.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;

	if (argc == 2 && ft_cub(argv[1]) == 1)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
			return (0);
		if (ft_init_game(game, argv[1]) == 0)
		{
			write(2, "Error\n open error", 17);
			//ft_freepasall(game);
			return (0);
		}
		i = 0;
		while (game->map.map[i] != NULL)
		{
			// printf("%s\n", game->map.map[i]);
			i++;
		}
		// printf("--------------\n");
		if (ft_parsing(game) == 0)
		{
			//ft_freeall(game);
			return (0);
		}
		// printf("--------------\n");
		// printf("%s\n", game->floor);
		// printf("%s\n", game->input[5]);
		// printf("--------------\n");
		// printf("%f\n", game->plpos.x);
		// printf("%f\n", game->plpos.y);


		if (ft_execgame(game) == 0)
		{
			free(game);
			return (0);
		}
		//ft_freeall(game);
	}
}
