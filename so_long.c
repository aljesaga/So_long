/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:22:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/04 12:24:03 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(int fd, t_game_struct **map, void *mlx)
{
}

void	ft_free_lts(t_game_struct *map)
{
	map->player_x = 0;
	map->player_y = 0;
	map->player = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->exit = 0;
	map->points = 0;
	map->all_points = 0;
	map->width = 0;
	while (map->high-- > 0)
		free(map->reading[map->high]);
	free(map->reading[0]);	
}

int	main(int arc, char **arv)
{
	int				fd;
	void			*mlx;
	t_game_struct	*game_map;

	if (arc == 2)
	{
		if (get_type(arv[1]) == 1)
		{
			fd = open(arv[1]);
			game_map->high = height(arv[1]);
			analysis(fd, game_map, game_map->high);
			mlx = mlx_init();
			load_map(fd, game_map, mlx);
		}
	}
	else
		printf("number of maps not exact\n");
	close(fd);
	return (0);
}
