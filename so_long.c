/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:22:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/22 18:03:38 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(int fd, t_game_struct **map, void *mlx)
{
	
}

int	main(int arc, char **arv)
{
	int				fd;
	void			*mlx;
	t_game_struct	**game_map;

	if (arc == 2)
	{
		if (type(arv[1]) == 1)
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
