/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:26:59 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/22 17:39:35 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPING_H
# define MAPING_H

# include "../../Libft/libft.h"
# include "../so_long.h"
# include <unistd.h>
# include <stdio.h>


/* prints */

void	send_error(int line, int point, int action);
int 	height(int fd);

/* analysis */

int	    	        type(char *arv);
void	            plus_values(int action, char x, int *values);
void	            other_line(char *str, int line, int length, int *values);
int		            error_map(char *str, int check, int *values, int end);
t_game_struct		analysis(int fd, char *map);

#endif