#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
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
int	close(int keycode, t_wlx *wlx);
int	key_up(int keycode, t_wlx *wlx);
int	key_down(int keycode, t_wlx *wlx);
int	key_left(int keycode, t_wlx *wlx);
int	key_right(int keycode, t_wlx *wlx);

#endif