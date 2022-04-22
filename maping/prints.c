/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:42:04 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/22 15:18:37 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print2_move(int x, int y, int check, t_mlx_need *mlx_st)
{
	if (check == 2)
	{
		if (mlx_st->map->reading[y][x - 1] == 'E')
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_exit.img, (x - 1) * 32, y * 32);
		else
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, (x - 1) * 32, y * 32);
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_player.img, x * 32, y * 32);
	}
	else if (check == 3)
	{
		if (mlx_st->map->reading[y - 1][x] == 'E')
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_exit.img, x * 32, (y - 1) * 32);
		else
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, x * 32, (y - 1) * 32);
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_player.img, x * 32, y * 32);
	}
}

void	print_move(int x, int y, int check, t_mlx_need *mlx_st)
{
	if (check >= 2)
		print2_move(x, y, check, mlx_st);
	else if (check == 0)
	{
		if (mlx_st->map->reading[y][x + 1] == 'E')
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_exit.img, (x + 1) * 32, y * 32);
		else
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, (x + 1) * 32, y * 32);
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_player.img, x * 32, y * 32);
	}
	else if (check == 1)
	{
		if (mlx_st->map->reading[y + 1][x] == 'E')
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_exit.img, x * 32, (y + 1) * 32);
		else
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, x * 32, (y + 1) * 32);
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
			mlx_st->img_player.img, x * 32, y * 32);
	}
}

void	send_error(int line, int point, int action)
{
	printf("Error\n");
	if (action == 1)
		printf("Incomplete external Wall, line %d, char %d\n", line, point);
	if (action == 2)
		printf("the line %d has a different size\n", line);
	if (action == 3)
		printf("too many players\n");
	if (action == 4)
		printf("too many exits");
	if (action == 5)
		printf("the player was not found\n");
	if (action == 6)
		printf("the exit was not found\n");
	if (action == 7)
		printf("try placing some collectible");
	if (action == 8)
		printf("the map cannot be square");
	if (action == 9)
		printf("line %d, char %d, not allowed\n", line, point);
	if (action == 0)
		printf("insufficient memory to render");
	exit (0);
}

int	height(char *arv)
{
	int		fd;
	int		end;
	char	*str;

	fd = open(arv, O_RDONLY);
	str = get_next_line(fd);
	end = 0;
	while (str != NULL)
	{
		end++;
		str = get_next_line(fd);
	}
	close(fd);
	printf("%d\n", end);
	return (end);
}
