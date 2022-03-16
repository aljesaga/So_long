/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:56:13 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/16 20:06:53 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*t_img	*ft_new_img(void *mlx, int width, int height)
{
	t_img	*img_st;

	img_st->img = mlx_new_image(mlx, width, height);
	img_st->size->x = width;
	img_st->size->y = height;
	img_st->px = mlx_get_data_addr(img_st->img, &img_st->b_px,
			&img_st->line_size, &img_st->endian);
	return (img_st);
}*/

t_img	ft_new_sprite(void *mlx, char *route)
{
	t_img	img_st;

	img_st.img = mlx_xpm_file_to_image(mlx, route, &img_st.size.x,
			&img_st.size.y);
	img_st.px = mlx_get_data_addr(&img_st.img, &img_st.b_px,
			&img_st.line_size, &img_st.endian);
	return (img_st);
}

void	ft_add_arts(t_mlx_need *mlx_st, t_game_struct *map)
{
	t_vtr	p;

	p.y = 0;
	while (p.y < map->high)
	{
		p.x = 0;
		while (map->reading[p.y][p.x] != '\0')
		{
			if (map->reading[p.y][p.x] == '1')
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
					mlx_st->img_wall.img, p.x * 32, p.y * 32);
			else if (map->reading[p.y][p.x] == 'P')
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
					mlx_st->img_player.img, p.x * 32, p.y * 32);
			else if (map->reading[p.y][p.x] == 'E')
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
					mlx_st->img_exit.img, p.x * 32, p.y * 32);
			else if (map->reading[p.y][p.x] == 'C')
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
					mlx_st->img_coll.img, p.x * 32, p.y * 32);
			else
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
					mlx_st->img_back.img, p.x * 32, p.y * 32);
			p.x++;
		}
		p.y++;
	}
}
