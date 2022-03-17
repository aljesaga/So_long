/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:50:25 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/17 15:26:51 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_img(t_img img_st)
{
	img_st.img = NULL;
	img_st.px = NULL;
	img_st.size.x = 0;
	img_st.size.y = 0;
	img_st.b_px = 0;
	img_st.line_size = 0;
	img_st.endian = 0;
}

void	ft_free_mlx(t_mlx_need *mlx_st)
{
	mlx_st->mlx = NULL;
	mlx_st->mlx_win = NULL;
	mlx_st->all_points = 0;
	mlx_st->points = 0;
	ft_free_img(mlx_st->img_player);
	ft_free_img(mlx_st->img_wall);
	ft_free_img(mlx_st->img_back);
	ft_free_img(mlx_st->img_exit);
	ft_free_img(mlx_st->img_coll);
	ft_free_map(mlx_st->map);
}

void	ft_free_map(t_game_struct *map)
{
	map->p_place.x = 0;
	map->p_place.y = 0;
	map->player = 0;
	map->e_place.x = 0;
	map->e_place.y = 0;
	map->exit = 0;
	map->points = 0;
	map->all_points = 0;
	map->width = 0;
	while (map->high-- > 0)
		free(map->reading[map->high]);
	free(map->reading[0]);
}
