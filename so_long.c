/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:22:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/06 19:50:13 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(int fd, int *measures, void *mlx)
{
	
}

int	height(char *arv)
{
	int fd2;
	int end;
	char *str;

	fd2 = open(arv);
	str = get_next_line(fd2);
	end == 0;
	while (str != NULL)
	{
		end++;
		str = get_next_line(fd2);
	}
	close(fd2);
	return (end);
}
int	main(int arc, char **arv)
{
	int		fd;
	int 	measures[2];
	void	*mlx;

	if (arc == 2)
	{
		fd = open(arv[1]);
		measures[0] = height(arv[1]);
		measures[1] = analysis(fd, arv[1], measures[0]);
		mlx = mlx_init();
		load_map(fd, measures, mlx);
	}
	else
		printf("number of maps not exact\n");
	close(fd);
	return (0);
}
