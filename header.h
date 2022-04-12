#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/libft/libft.h"
#include "minilibx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_wlx
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
}	t_platform;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}	t_block;

typedef struct s_image
{
	char*				relative_path;
	struct s_wlx		wlx;
	void 				*img;
	int					x;
	int 				y;
	int					img_height;
	int					img_width;
}	t_image;

typedef struct s_player
{
	int 			x;
	int 			y;
	int				pos;
	struct s_wlx 	wlx;
	struct s_image	image;
	char			*relative_path;
	char			*name;
} t_player;

typedef struct s_game
{
	struct s_wlx			wlx;
	struct s_platform		platform;
	struct s_block			block;
	struct s_player			player;
	struct s_key_control	*key_control;
} t_game;

typedef struct s_key_control
{
	char	*name;
	int		key_code;
	int		(*f)(t_game *);
} t_key_control;


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 64
#endif

unsigned long	rgb_hex(int r, int g, int b);
void			*put_image(t_image image);
void			create_map(t_wlx wlx, t_platform platform);
t_block			set_block(char name);
int				game_exit(int keycode, t_wlx *wlx);
char			*get_next_line(int fd);
void			*myfree(void *str);
void			create_map_line(char *area, t_wlx wlx, int *i);
char			**create_map_matris(t_platform platform);
//key_hook

int				key_up(t_game *game);
int				key_down(t_game *game);
int				key_left(t_game *game);
int				key_right(t_game *game);
int				key_hook(int keycode, t_game *game);

int				image_move_down(t_game *game);
int 			image_move_up(t_game *game);
int 			image_move_left(t_game *game);
int 			image_move_right(t_game *game);

//static
t_block *block_array();
#endif