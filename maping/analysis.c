/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:24:37 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/23 17:25:50 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "maping.h"

int	type(char *arv)
{
	int	i;

	i = 0;
	while (arv[i] != '.' || arv[i])
		i++;
	if (arv[i +1] == 'b' && arv[i + 2] == 'e' && arv[i + 3] == 'r')
		return (1);
	return (0);
}

void	plus_values(int x, int y, char k, t_game_struct *map)
{
	if (k == 'x')
	{
		map->player = 0;
		map->exit = 0;
		map->all_points = 0;
	}
	if (k == 'P')
	{
		if (map->player == 1)
			send_error(action, action, 3);
		map->player = 1;
		map->player_x = x;
		map->player_y = y;
	}
	if (k == 'E')
	{
		if (map->exit == 1)
			send_error(action, action, 4);
		map->exit = 1;
		map->exit_x = x;
		map->exit_y = y;
	}
	if (k == 'C')
		map->all_points++;
}

void	other_line(char *str, int line, int length, t_game_struct *map)
{
	int	p;

	p = -1;
	if (line == 1)
		plus_values(0, 'x', map);
	while (str[++p] != '\0')
	{
		if (str[0] != 1)
			send_error(line, p, 1);
		else if (str[p] != 1 && str[p] != 0 && str[p] != 'P'
			&& str[p] != 'E' && str[p] != 'C')
			send_error(line, p, 9);
		else if (str[p] == 'P' || str[p] == 'E' || str[p] == 'C')
			plus_values(p, line, str[p], map);
	}
	if (str[p] != 1)
		send_error(line, p, 1);
	if (p != length)
		send_error(line, p, 2);
}

void	error_map(char *str, int check, int end, t_game_struct *map)
{
	int			point;

	if (check == 0 || check == end)
	{
		point = -1;
		while (str[++point] != '\0')
		{
			if (str[point] != 1)
				sent_error(check, point, 1);
		}
		if (check == end)
			if (length != point)
				send_error(check, point, 2);
		map->width = point;
		if (map->width == end)
			send_error(check, point, 8);
	}
	else
		other_line(str, check, map->width, map);
}

void	analysis(int fd, t_game_struct *game_map, int end)
{
	t_game_struct	*map;
	int				line;

	line = -1;
	map = game_map;
	map->reading = malloc(sizeof(char *) * end + 1);
	if (!map->reading)
		send_error(line, end, 0);
	while (++line < end)
	{
		map->reading[line] = get_next_line(fd);
		error_map(map->reading[line], line, end);
	}
	if (map->player < 1)
		send_error(time, end, 5);
	if (map->exit < 1)
		send_error(time, end, 6);
	if (map->all_points < 1)
		send_error(time, end, 7);
}
