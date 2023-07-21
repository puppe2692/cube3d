void	ft_handle_keymvt(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		if (game->map.map[(int)(game->plpos.x + game->dir.x * game->speed.movespeed)][(int)(game->plpos.y)] == 0) 
			game->plpos.x += game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y + game->dir.y * game->speed.movespeed)] == 0)
			game->plpos.y += game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_s)
	{
		if (game->map.map[(int)(game->plpos.x - game->dir.x * game->speed.movespeed)][(int)(game->plpos.y)] == 0) 
			game->plpos.x -= game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y - game->dir.y * game->speed.movespeed)] == 0)
			game->plpos.y -= game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_a)
	{
		if (game->map.map[(int)(game->plpos.x + game->plan.x * game->speed.movespeed)][(int)(game->plpos.y)] == 0) 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y + game->plan.y * game->speed.movespeed)] == 0)
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
	if (keysym == XK_d)
	{
		if (game->map.map[(int)(game->plpos.x + game->plan.x * game->speed.movespeed)][(int)(game->plpos.y)] == 0) 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y + game->plan.y * game->speed.movespeed)] == 0)
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
}


	if (keysym == XK_w)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->dir.x * game->speed.movespeed)] == 0) 
			game->plpos.x += game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->dir.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y += game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_s)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x - game->dir.x * game->speed.movespeed)] == 0) 
			game->plpos.x -= game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y - game->dir.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y -= game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_a)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->plan.x * game->speed.movespeed)] == 0) 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->plan.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
	if (keysym == XK_d)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->plan.x * game->speed.movespeed)] == 0) 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->plan.y * game->speed.movespeed)][(int)(game->plpos.x)] == 0)
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}

	void	ft_draw(t_game *game, int x)
{
	game->draw.lineheight = (int)(game->res.y / game->perpwalldist);
	printf("--------------\n");
	printf("LINE HEIGHT %i\n", game->draw.lineheight);
	printf("RES %i\n", game->res.y);
	printf("perpwall %f\n", game->perpwalldist);
	printf("DS %i\n", game->draw.drawstart);
	printf("DE %i\n", game->draw.drawend);
	printf("movespeed : %f\n", game->speed.movespeed);
	printf("rotspeed : %f\n", game->speed.rotspeed);
	printf("frametime : %f\n", game->speed.frametime);
	printf("--------------\n");
	game->draw.drawstart = -game->draw.lineheight / 2 + game->res.y / 2;
	if (game->draw.drawstart < 0)
		game->draw.drawstart = 0;
	game->draw.drawend = game->draw.lineheight / 2 + game->res.y / 2;
	if (game->draw.drawend >= game->res.y)
		game->draw.drawend = game->res.y - 1;
	ft_color(game, x);
}

void	ft_color(t_game *game, int x)
{
	int	j;

	j = 0;
	while (j < game->res.y)
	{
		if (j >= game->draw.drawstart && j <= game->draw.drawend)
		{
			game->draw.color = 0xFF00;
			if (game->side == 1)
				game->draw.color = game->draw.color / 3;
		}
		else
			game->draw.color = 0x0000;
		mlx_pixel_put(game->mlx, game->win, x, j, game->draw.color);
		j++;
	}
}

|| x_round >= (int) ft_strlen(game->map.map[y_round])




void	ft_handle_keymvt(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		if (game->map.map[(int)(game->plpos.x + game->dir.x * game->speed.movespeed)][(int)(game->plpos.y)] != '1') 
			game->plpos.x += game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y + game->dir.y * game->speed.movespeed)] != '1')
			game->plpos.y += game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_s)
	{
		if (game->map.map[(int)(game->plpos.x - game->dir.x * game->speed.movespeed)][(int)(game->plpos.y)] != '1') 
			game->plpos.x -= game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y - game->dir.y * game->speed.movespeed)] != '1')
			game->plpos.y -= game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_a)
	{
		if (game->map.map[(int)(game->plpos.x + game->plan.x * game->speed.movespeed)][(int)(game->plpos.y)] != '1') 
			game->plpos.x -= game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y + game->plan.y * game->speed.movespeed)] != '1')
			game->plpos.y -= game->plan.y * game->speed.movespeed;
	}
	if (keysym == XK_d)
	{
		if (game->map.map[(int)(game->plpos.x + game->plan.x * game->speed.movespeed)][(int)(game->plpos.y)] != '1') 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.x)][(int)(game->plpos.y + game->plan.y * game->speed.movespeed)] != '1')
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
}


void	ft_handle_cammvt(int keysym, t_game *game)
{
	double	olddirx;
	double	oldplanex;

	if (keysym == XK_Left)
	{
		olddirx = game->dir.x;
		game->dir.x = game->dir.x * cos(-game->speed.rotspeed) - game->dir.y * sin(-game->speed.rotspeed);
		game->dir.y = olddirx * sin(-game->speed.rotspeed) + game->dir.y * cos(-game->speed.rotspeed);
		oldplanex = game->plan.x;
		game->plan.x = game->plan.x * cos(-game->speed.rotspeed) - game->plan.y * sin(-game->speed.rotspeed);
		game->plan.y = oldplanex * sin(-game->speed.rotspeed) + game->plan.y * cos(-game->speed.rotspeed);
	}
	if (keysym == XK_Right)
	{
		olddirx = game->dir.x;
		game->dir.x = game->dir.x * cos(game->speed.rotspeed) - game->dir.y * sin(game->speed.rotspeed);
		game->dir.y = olddirx * sin(game->speed.rotspeed) + game->dir.y * cos(game->speed.rotspeed);
		oldplanex = game->plan.x;
		game->plan.x = game->plan.x * cos(game->speed.rotspeed) - game->plan.y * sin(game->speed.rotspeed);
		game->plan.y = oldplanex * sin(game->speed.rotspeed) + game->plan.y * cos(game->speed.rotspeed);
	}
}

void	ft_handle_keymvt(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->dir.x * game->speed.movespeed)] != '1') 
			game->plpos.x += game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->dir.y * game->speed.movespeed)][(int)(game->plpos.x)] != '1')
			game->plpos.y += game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_s)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x - game->dir.x * game->speed.movespeed)] != '1') 
			game->plpos.x -= game->dir.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y - game->dir.y * game->speed.movespeed)][(int)(game->plpos.x)] != '1')
			game->plpos.y -= game->dir.y * game->speed.movespeed;
	}
	if (keysym == XK_a)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->plan.x * game->speed.movespeed)] != '1') 
			game->plpos.x -= game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->plan.y * game->speed.movespeed)][(int)(game->plpos.x)] != '1')
			game->plpos.y -= game->plan.y * game->speed.movespeed;
	}
	if (keysym == XK_d)
	{
		if (game->map.map[(int)(game->plpos.y)][(int)(game->plpos.x + game->plan.x * game->speed.movespeed)] != '1') 
			game->plpos.x += game->plan.x * game->speed.movespeed;
		if (game->map.map[(int)(game->plpos.y + game->plan.y * game->speed.movespeed)][(int)(game->plpos.x)] != '1')
			game->plpos.y += game->plan.y * game->speed.movespeed;
	}
}


void    ft_complete_algo_texture(t_game game, t_algo *algo)
{
    algo->img_tex = ft_get_img(game, *algo);
    if (algo->side == 0)
        algo->wallx = algo->pos.y + algo->perpwalldist * algo->raydir.y;
    else
        algo->wallx = algo->pos.x + algo->perpwalldist * algo->raydir.x;
    algo->wallx -= (int) floor((algo->wallx));
    algo->step_d = 1.0 * algo->img_tex.height / algo->lineheight;
    algo->texx = (int)(algo->wallx * (double)algo->img_tex.width);

    if (algo->side == 0 && algo->raydir.x > 0)
        algo->texx = algo->img_tex.width - algo->texx - 1;
    if (algo->side == 1 && algo->raydir.y < 0)
        algo->texx = algo->img_tex.width - algo->texx - 1;
		
    algo->texpos = (algo->drawstart - WIN_HEIGHT / 2 + algo->lineheight / 2)
        * algo->step_d;
}

	if (game->side == 0 && game->raydir.x > 0)
		game->texture.x = game->wall.texture_to_render->width - game->texture.x - 1; // ici
	if (game->side == 1 && game->raydir.y < 0)
		game->texture.x = game->wall.texture_to_render->width - game->texture.x - 1;
		