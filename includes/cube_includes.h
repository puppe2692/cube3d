/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_includes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/27 11:50:11 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_INCLUDES_H
# define CUBE_INCLUDES_H

# include "../libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <string.h>
# include <stdio.h>

typedef struct s_wall
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_img	*n;
	t_img	*s;
	t_img	*e;
	t_img	*w;
}	t_wall;

typedef struct s_game
{
	char	**input;
	int		inputsize;
	t_wall	wall;
	char	*floor;
	char	*roof;
	char	**fcol;
	char	**rcol;
	int		vinputnbr;
	char	**map;
	void	*mlx;
}	t_game;


// main
int		ft_cub(char *str);
int		main(int argc, char **argv);

// initialisation
int		ft_mapsize(char *str);
char	**ft_readmap(t_game *game, char *str);
char	*ft_findinput(t_game *game, char *str);
int		ft_init_game(t_game *game, char *str);

//Parsing
int		ft_vwronginput(t_game *game);
int		ft_vinput(t_game *game);
int		ft_vimage(t_game *game);
int		ft_vcolor(t_game *game);
int		ft_parsing(t_game *game);

#endif