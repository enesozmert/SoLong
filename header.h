/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:48:20 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 13:30:08 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "include/libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_wlx
{
	void	*mlx;
	void	*win;
}	t_wlx;

typedef struct s_platform
{
	char	**map;
	int		pos_x;
	int		pos_y;
	int		height;
	int		width;
	int		multiple;
	char	*path;
	int		fd;
}	t_platform;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}	t_block;

typedef struct s_image
{
	char			*relative_path;
	struct s_wlx	wlx;
	void			*img;
	int				x;
	int				y;
	int				img_height;
	int				img_width;
}	t_image;

typedef struct s_player
{
	int				x;
	int				y;
	int				direction;
	int				coin_count;
	int				coin_size;
	int				move_count;
	struct s_wlx	wlx;
	struct s_image	image;
	char			*relative_path;
	char			*name;
	char			*perspective;
}	t_player;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				enemy_index;
	int				enemy_speed;
}	t_enemy;

typedef struct s_exception
{
	int				error_code;
	char			*message;
	int				(*f)(t_platform);
}	t_exception;

typedef struct s_game
{
	struct s_wlx			wlx;
	struct s_platform		platform;
	struct s_block			block;
	struct s_player			player;
	struct s_key_control	*key_control;
	struct s_enemy			enemy;
}	t_game;

typedef struct s_key_control
{
	char	*name;
	int		key_code;
	int		(*f)(t_game *);
}	t_key_control;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};
# ifndef BLOCK_SIZE
#  define BLOCK_SIZE 64
# endif

unsigned long		rgb_hex(int r, int g, int b);
void				*put_image(t_image image);
void				create_map(t_wlx wlx, t_platform platform);
t_block				set_block(char name);
int					game_exit(int keycode, t_wlx *wlx);
char				*get_next_line(int fd);
void				*myfree(void *str);
void				create_map_line(char *area, t_wlx wlx, int *i);
char				**create_map_matris(t_platform platform);
//key_hook
int					key_up(t_game *game);
int					key_down(t_game *game);
int					key_left(t_game *game);
int					key_right(t_game *game);
int					key_hook(int keycode, t_game *game);
void				player_move_base(t_game *game);
int					player_move(t_game *game, int x, int y);
//fill
void				fill_background_base(t_game *game, int x, int y);
int					*map_size(t_platform platform);
int					map_line_count(t_platform platform);
//player
char				*player_perspective(t_game game);
void				player_move_area(t_game *game);
int					player_move_wall(t_game *game);
void				player_move_coin(t_game *game);
void				player_move_count(t_game *game);
void				player_move_exit(t_game *game);
//locations
int					*get_location(t_platform *platform, char block_name);
int					get_block_count(t_platform *platform, char block_name);
//main
void				player_main(t_game *game);
void				load_main(t_game *game, t_wlx *wlx);
void				control_main(t_game *game, char **av, int ac);
//main_b
void				player_main_b(t_game *game);
void				load_main_b(t_game *game, t_wlx *wlx);
void				control_main_b(t_game *game, char **av, int ac);
//anim_b
int					animation(t_game *game);
void				move_animation(t_game *game);
void				animator_coin(t_game *game, int x, int y);
//exception handler
void				exception_handler(t_platform platform);
int					map_error(t_platform platform);
int					item_repeat_error(t_platform platform);
int					item_single_error(t_platform platform);
int					item_wrong_error(t_platform platform);
int					file_error(t_platform platform);
//enemy_move
void				update2(t_game *game, int x, int y);
void				move_2(t_game *game, int x, int y);
void				move_4(t_game *game, int x, int y);
//screen_print_move_count
void				print_map_string(t_game *game);
//item_control
int					check_door(t_game *game);
int					check_wall(t_game *game);
int					check_total_item(t_game *game);
//get_next_line
char				*get_next_line(int fd);
void				*myfree(void *str);
#endif
