/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_includes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/07/21 12:46:35 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_INCLUDES_H
# define CUBE_INCLUDES_H

# include "../libft/libft.h"
# include <math.h>
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

# define PLAN 0.66

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
	t_img	*texture_to_render;
}	t_wall;

typedef struct s_map
{
	char	**map;
	int		haut;
	int		larg;
}	t_map;

typedef struct s_pos
{
	int			x;
	int			y;
}	t_pos;

typedef struct s_dpos
{
	double			x;
	double			y;
}	t_dpos;

typedef struct s_time
{
	double			time;
	double			oldtime;
}	t_time;

typedef struct s_speed
{
	double			frametime;
	double			movespeed;
	double			rotspeed;
}	t_speed;

typedef struct s_draw
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
}	t_draw;

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
	void	*win;
	int		dstr;
	t_pos	res;
	t_map	map;
	t_dpos	plpos;
	t_dpos	dir;
	t_dpos	plan;
	t_time	time;
	double	camerax;
	t_dpos	raydir;
	t_dpos	sidedist;
	t_dpos	deltadist;
	t_pos	step;
	t_pos	mapbox;
	int		hit;
	double	perpwalldist;
	int		side;
	t_dpos	texture;
	double	wallx;
	t_draw	draw;
	t_speed	speed;
	int		bool;
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
char	**ft_init_map(t_game *game);
void	ft_mapcopy(t_game *game, char **new);
char	**ft_mapmalloc(t_game *game, char **new);
void	ft_hautlarg(t_game *game);

//Parsing
int		ft_spacecount(char *str);
int		ft_vwronginput(t_game *game);
int		ft_vinput(t_game *game);
int		ft_vimage(t_game *game);
int		ft_parsing(t_game *game);

//Parsing_2
int		ft_convertdir(t_game *game);
int		ft_convertcolor(t_game *game);
int		ft_vcolor_suite(char **hex);
int		ft_nbrcolor(t_game *game);
int		ft_vcolor(t_game *game, int i);

//Parsing_Map
int		ft_vmapinput(t_game *game, int i);
int		ft_vmapwall_2(t_game *game, int i, int j);
int		ft_vmapwall(t_game *game);
int		ft_parsingmap(t_game *game);

//Parsing_Map_2
void	ft_init_dir(t_game *game, double x, double y);
void	ft_init_plan(t_game *game, double x, double y);
int		ft_closespace(t_game *game, int i, int j);
int		ft_vmapwall_space(t_game *game);

//key press
int		ft_handle_keypress(int keysym, t_game *game);
void	ft_handle_cammvt(int keysym, t_game *game);
void	ft_handle_keymvt(int keysym, t_game *game);

//exectest
int		ft_map_limits(t_game *game, double x, double y);
void	ft_init_value(t_game *game);
void	ft_init_ray(t_game *game, int x);
void	ft_init_deltadist(t_game *game);
void	ft_init_step(t_game *game);
void	ft_init_sidedist(t_game *game);
void	ft_launchray(t_game *game);
int		ft_rendermap(t_game *game);
int		ft_execgame(t_game *game);

//draw
void	ft_draw(t_game *game, int x);
void	ft_texture_to_render(t_game *game);
void	ft_wall_setting(t_game *game);
void	ft_render_line(t_game *game, int x);
void	ft_data_init(t_game *game, double *data);
int		ft_get_pix_color(t_game *game);
int		ft_get_rgb_color(char **color);

//free_mngmt
void	ft_destroy_image(t_game *game);
void	ft_dblstrfree(char **sstr, int j);
void	ft_freeall(t_game *game);
void	ft_freepasall(t_game *game, int i);
void	ft_freedir(t_game *game);
void	ft_freecol(t_game *game);
void	ft_destroy_game(t_game *game);
int		ft_handle_d(t_game *game);
void	ft_freesplit(char **sstr);

#endif