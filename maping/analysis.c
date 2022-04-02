/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:24:37 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/02 13:50:43 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_type(char *arv)
{
	int	i;

	i = 0;
	while (arv[i] != '\0')
	{
		if (arv[i] == '.')
			if (arv[i + 1] == 'b' && arv[i + 2] == 'e' && arv[i + 3] == 'r')
				return (1);
		i++;
	}
	return (0);
}

void	plus_values(int x, int y, char k, t_game_struct *map)
{
	if (k == 'x')
	{
		map->player = 0;
		map->exit = 0;
		map->all_points = 0;
		map->points = 0;
	}
	if (k == 'P')
	{
		if (map->player == 1)
			send_error(x, y, 3);
		map->player++;
		map->p_place.x = x;
		map->p_place.y = y;
	}
	else if (k == 'E')
	{
		if (map->exit == 1)
			send_error(x, y, 4);
		map->exit++;
		map->e_place.x = x;
		map->e_place.y = y;
	}
	else if (k == 'C')
		map->all_points++;
}

void	other_line(char *str, int line, int length, t_game_struct *map)
{
	int	p;

	p = 0;
	if (line == 1)
		plus_values(0, 0, 'x', map);
	while (str[p + 1] != '\0')
	{
		if (str[0] != '1')
			send_error(line, p, 1);
		else if (str[p] != '1' && str[p] != '0' && str[p] != 'P'
			&& str[p] != 'E' && str[p] != 'C')
			send_error(line, p, 9);
		else if (str[p] == 'P' || str[p] == 'E' || str[p] == 'C')
			plus_values(p, line, str[p], map);
		p++;
	}
	if (str[p - 1] != '1')
		send_error(line, p, 1);
	if (p != length)
		send_error(line, p, 2);
}

void	error_map(char *str, int check, int end, t_game_struct *map)
{
	int			point;

	if (check == 0 || check == end - 1)
	{
		point = 0;
		while (str[point + 1] != '\0')
		{
			if (str[point] != '1')
				send_error(check, point, 1);
			point++;
		}
		if (check == end - 1)
			if (point + 1 != map->width)
				send_error(check, point, 2);
		map->width = point;
		if (map->width == end - 1)
			send_error(check, point, 8);
	}
	else
		other_line(str, check, map->width, map);
}

void	analysis(int fd, t_game_struct *map, int end)
{
	int				line;

	line = -1;
	map->reading = malloc(sizeof(char *) * end + 1);
	if (!map->reading)
		send_error(line, end, 0);
	while (++line < end)
	{
		map->reading[line] = get_next_line(fd);
		error_map(map->reading[line], line, end, map);
	}
	if (map->player < 1)
		send_error(line, end, 5);
	if (map->exit < 1)
		send_error(line, end, 6);
	if (map->all_points < 1)
		send_error(line, end, 7);
}
