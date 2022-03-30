
#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_wlx	wlx;
	t_data	img;

	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, 3840, 2160, "Ecole 42 eozmert");
	img.img = mlx_new_image(wlx.mlx, 3840, 2160);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3840)
	{
		j = 0;
		while (j < 2160)
		{
			if (i % 2 != 0 || i == 0 || j == 99 || j % 2 != 0)
			{
				my_mlx_pixel_put(&img, i, j, rgb_hex(j % 255, (int)(i * j) % 255, i % 255));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(wlx.mlx, wlx.win, img.img, 0, 0);
	mlx_hook(wlx.win, 2, 1L<<0, close, &wlx);
	mlx_key_hook(wlx.win, key_up, &wlx);
	mlx_key_hook(wlx.win, key_down, &wlx);
	mlx_key_hook(wlx.win, key_left, &wlx);
	mlx_key_hook(wlx.win, key_right, &wlx);
	//mlx_key_hook(wlx.win, close, &wlx);
	mlx_loop(wlx.mlx);
}