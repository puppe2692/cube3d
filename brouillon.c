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