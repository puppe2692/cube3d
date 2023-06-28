/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_includes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/28 18:31:23 by nwyseur          ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		haut;
	int		larg;
}	t_map;

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
	void	*mlx;
	t_map	map;
}	t_game;


//Main
int		ft_cub(char *str);
int		main(int argc, char **argv);

//Init_data
int		ft_mapsize(char *str);
char	**ft_readmap(t_game *game, char *str);
char	*ft_findinput(t_game *game, char *str);
int		ft_init_game(t_game *game, char *str);

//Init_map
int		ft_init_map(t_game *game);
void	ft_mapcopy(t_game *game);
int		ft_mapmalloc(t_game *game);
void	ft_hautlarg(t_game *game);

//Parsing
int		ft_vwronginput(t_game *game);
int		ft_vinput(t_game *game);
int		ft_vimage(t_game *game);
int		ft_parsing(t_game *game);

//Parsing_2
void	ft_convertdir(t_game *game);
int		ft_vcolor(t_game *game);
int		ft_vcolor_suite(char **hex);
void	ft_convertcolor(t_game *game);

#endif