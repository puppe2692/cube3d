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