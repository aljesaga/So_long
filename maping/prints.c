/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:42:04 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/23 17:26:07 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "maping.h"

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
		printf("line %d, char %d, not allowed\n");
	if (action == 0)
		printf("insufficient memory to render");
	exit (0);
}

int	height(char *arv)
{
	int		fd2;
	int		end;
	char	*str;

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
