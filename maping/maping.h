/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinig.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:26:59 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/21 17:35:25 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPING_H
# define MAPING_H

# include "../../Libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>


/* prints */

void	send_error(int line, int point, int action);

/* analysis */

int		type(char *arv);
void	plus_values(int action, char x, int *values);
void	other_line(char *str, int line, int length, int *values);
int		error_map(char *str, int check, int *values, int end);
int		analysis(int fd, char *map, int end);

#endif