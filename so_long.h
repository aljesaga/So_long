/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:38:23 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/21 17:50:11 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H

# define SO_LONG_H

# include "../Libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>

typedef struct game_struct
{
    int     high;
    int     width;
    int     player_x;
    int     player_y;
    int     all_points;
    int     points;
    int     exit_x;
    int     exit_y;

};


/* so_long */

int		main(int arc, char **arv);

#endif
