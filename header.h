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
}				t_data;

typedef struct	s_wlx
{
	void	*mlx;
	void	*win;
}				t_wlx;

typedef struct s_platform
{
	// char	**map;
	// int		pos_x;
	// int		pos_y;
	// int		chr_x;
	// int		chr_y;
	// int		multiple;
	char	*path;
}	t_platform;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}	t_block;

typedef struct s_image
{
	char	*relative_path;
	struct s_wlx wlx;
	void *img;
	int	x;
	int y;
	int img_height;
	int img_width;
}	t_image;



enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

unsigned long rgb_hex(int r, int g, int b);
void *put_image(t_image image);
void create_map(t_wlx wlx, t_platform platform);
t_block set_block(char name);
int	game_exit(int keycode, t_wlx *wlx);
int	key_up(int keycode, t_wlx *wlx);
int	key_down(int keycode, t_wlx *wlx);
int	key_left(int keycode, t_wlx *wlx);
int	key_right(int keycode, t_wlx *wlx);
char *get_next_line(int fd);
void *myfree(void *str);
void line_by_line(char *area, t_wlx wlx, int *i);

#endif