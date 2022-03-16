/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:38:23 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/16 19:27:04 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "./gnl/get_next_line.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_vtr
{
	int	x;
	int	y;

}	t_vtr;

typedef struct s_game_struct
{
	char	**reading;
	t_vtr	p_place;
	t_vtr	e_place;
	int		high;
	int		width;
	int		all_points;
	int		points;
	int		player;
	int		exit;

}	t_game_struct;

typedef struct s_img
{
	void	*img;
	char	*px;
	t_vtr	size;
	int		b_px;
	int		line_size;
	int		endian;

}	t_img;

typedef struct s_mlx_need
{
	void	*mlx;
	void	*mlx_win;
	t_img	img_player;
	t_img	img_wall;
	t_img	img_back;
	t_img	img_exit;
	t_img	img_coll;
	int		all_points;
	int		points;

}	t_mlx_need;

/* so_long */

void	load_map(int fd, t_game_struct *map, t_mlx_need *mlx_all);
void	ft_free_lts(t_game_struct *map, int check);
int		main(int arc, char **arv);

/* ipu.c */

t_img	*ft_new_img(void *mlx, int width, int height);
t_img	ft_new_sprite(void *mlx, char *route);
void	ft_add_arts(t_mlx_need *mlx_st, t_game_struct *map);

/* keys_move */
/* wasd */

void	W_key(t_game_struct *map, void *mlx);
void	S_key(t_game_struct *map, void *mlx);
void	A_key(t_game_struct *map, void *mlx);
void	D_key(t_game_struct *map, void *mlx);
void	ft_end_map(t_game_struct *map, void *mlx);

/* maping */
/* prints */

void	send_error(int line, int point, int action);
int		height(char *arv);

/* analysis */

int		get_type(char *arv);
void	plus_values(int x, int y, char k, t_game_struct *map);
void	other_line(char *str, int line, int length, t_game_struct *map);
void	error_map(char *str, int check, int end, t_game_struct *map);
void	analysis(int fd, t_game_struct *map, int end);
#endif
