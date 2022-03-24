/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:56:13 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/24 19:47:22 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_new_sprite(void *mlx, char *route)
{
	t_img	img_st;

	img_st.img = mlx_xpm_file_to_image(mlx, route, &img_st.size.x,
			&img_st.size.y);
	img_st.px = mlx_get_data_addr(&img_st.img, &img_st.b_px,
			&img_st.line_size, &img_st.endian);
	return (img_st);
}

void	ft_charge_arts(t_mlx_need *mlx_a)
{
	mlx_a->img_back = ft_new_sprite(mlx_a->mlx, "./arts/flor.xmp");
	mlx_a->img_wall = ft_new_sprite(mlx_a->mlx, "./arts/wall.xmp");
	mlx_a->img_player = ft_new_sprite(mlx_a->mlx, "./arts/player.xmp");
	mlx_a->img_coll = ft_new_sprite(mlx_a->mlx, "./arts/colection.xmp");
	mlx_a->img_exit = ft_new_sprite(mlx_a->mlx, "./arts/exit.xmp");
	mlx_a->moves = 0;
}

void	ft_put_pec(t_mlx_need *mlx_st, int y, int x, char c)
{
	if (c == 'P')
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_player.img, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_exit.img, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_coll.img, x * 32, y * 32);
}

void	ft_add_arts(t_mlx_need *mlx_st, t_game_struct *map)
{
	t_vtr	p;

	p.y = 0;
	while (p.y < map->high)
	{
		p.x = 0;
		while (map->reading[p.y][p.x])
		{
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, p.x * 32, p.y * 32);
			if (map->reading[p.y][p.x] == '1')
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
					mlx_st->img_wall.img, p.x * 32, p.y * 32);
			else
				ft_put_pec(mlx_st, p.y, p.x, map->reading[p.y][p.x]);
			p.x++;
		}
		p.y++;
	}
}
