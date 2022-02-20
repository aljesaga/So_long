/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:38:23 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/06 19:26:07 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H

# define SO_LONG_H

# include "../Libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>

/* prints */

void	send_error(int line, int point, int action);

/* analysis */

int		type(char *arv);
void	plus_values(int action, char x, int *values);
void	other_line(char *str, int line, int length, int *values);
int		error_map(char *str, int check, int *values, int end);
int		analysis(int fd, char *map, int end);

/* so_long */

int		main(int arc, char **arv);

#endif
