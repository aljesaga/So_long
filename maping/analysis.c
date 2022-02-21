/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:24:37 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/21 17:34:10 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maping.h"

int type(char *arv)
{
	int	i;

	i = 0;
	while(arv[i] != '.' || arv[i])
		i++;
	if (arv[i +1] == 'b' && arv[i + 2] == 'e' && arv[i + 3] == 'e')
		return (1);
	return (0);
}

void	plus_values(int action, char x, int *values)
{
	if (action = 0)
	{
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
	}
	if (action == 1 && x == 'P')
	{
		if (values[0] == 1)
			send_error(action, action, 3);
		values[0] = 1;
	}
	if (action == 1 && x == 'E')
	{
		if (values[1] == 1)
			send_error(action, action, 4);
		values[1] = 1;
	}
	if (action == 1 && x == 'C')
		values[2]++;
}

void	other_line(char *str, int line, int length, int *values)
{
	int *values;
	int p;

	p = -1;
	if (line = 1)
		plus_values(0, 'x', values);
	while (str[++p] != '\0')
	{
		if (str[0] != 1)
			send_error(line, p, 1);
		else if (str[p] != 1 && str[p] != 0 && str[p] != 'P' && str[p] != 'E' && str[p] != 'C')
			send_error(line, p, 9);
		else if (str[p] == 'P' || str[p] == 'E' || str[p] == 'C')
			plus_values(1, str[p], values);
	}
	if (str[p] != 1)
		send_error(line, p, 1);
	if (str[p] != length)
		send_error(line, p, 2);
}

int	error_map(char *str, int check, int *values, int end)
{
	static int	length;
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
		length = point;
		if (length == end)
			send_error(check, point, 8);
	}
	else
		values = other_line(str, check, length);
	return (length);
}

int	analysis(int fd, char *map, int end)
{
	char	*str;
	int		time[2];
	int		values[3];

	time = 0;
	if (type(map) == 1)
	{
		str = get_next_line(map);
		while(str != NULL)
		{
			time[1] = error_map(str, time[0], values, end);
			str = get_next_line(fd);
			time[0]++;
		}
		if( values[0] < 1)
			send_error(time, end, 5);
		if (values[1] < 1)
			send_error(time, end, 6);
		if (values[2] < 1)
			send_error(time, end, 7);
		free(values);
		return (time[1]);
	}
}