/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:38:23 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/23 17:22:14 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "./maping/maping.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_game_struct
{
	int		high;
	int		width;
	int		player_x;
	int		player_y;
	int		all_points;
	char	**reading;
	int		points;
	int		exit_x;
	int		exit_y;
	int		player;
	int		exit;

}	t_game_struct;

/* so_long */

int		main(int arc, char **arv);

#endif
