/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:38:23 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/03 13:22:17 by alsanche         ###   ########lyon.fr   */
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
	void			*mlx;
	void			*mlx_win;
	t_img			img_player;
	t_img			img_wall;
	t_img			img_back;
	t_img			img_exit;
	t_img			img_coll;
	int				moves;
	t_game_struct	*map;

}	t_mlx_need;

/* so_long */

void	load_map(t_game_struct *map, t_mlx_need *mlx_all);
int		main(int arc, char **arv);

/* ipu */

t_img	ft_new_sprite(void *mlx, char *route);
void	ft_charge_arts(t_mlx_need *mlx_a);
void	ft_put_pec(t_mlx_need *mlx_st, int y, int x, char c);
void	ft_add_arts(t_mlx_need *mlx_st, t_game_struct *map);

/* ft_free */

void	ft_free_img(t_img img_st);
void	ft_free_mlx(t_mlx_need *mlx_st);
void	ft_free_map(t_game_struct *map);

/* keys_move */
/* hooks */

int		call_of_hooks(int key, t_mlx_need *mlx_st);
void	what_if(t_mlx_need *mlx_st);

/* wasd */

int		w_key(t_mlx_need *mlx);
int		s_key(t_mlx_need *mlx);
int		a_key(t_mlx_need *mlx);
int		d_key(t_mlx_need *mlx);
int		ft_end_game(t_mlx_need *mlx);

/* maping */
/* prints */

void	print_move(int x, int y, int check, t_mlx_need *mlx_st);
void	send_error(int line, int point, int action);
int		height(char *arv);

/* analysis */

int		get_type(char *arv);
void	plus_values(int x, int y, char k, t_game_struct *map);
void	other_line(char *str, int line, int length, t_game_struct *map);
void	error_map(char *str, int check, int end, t_game_struct *map);
void	analysis(int fd, t_game_struct *map, int end);
#endif
