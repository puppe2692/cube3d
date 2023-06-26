/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_includes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/06/26 14:49:14 by nwyseur          ###   ########.fr       */
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

typedef struct s_game
{
	char	**input;
	int		inputsize;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*roof;
	int		vinputnbr;
	char	**map;
	
	char	*map_str;
	int		map_length;
	int		map_width;
	int		collec;
	int		player;
	int		ppx;
	int		ppy;
	int		end;
	int		nb_move;
	int		nb_cc;
	void	*mlx;
	void	*win;
	int		img_size;
	int		win_width;
	int		win_height;
	int		dstr;
	t_img	*sw;
	t_img	*sf;
}	t_game;

#endif
