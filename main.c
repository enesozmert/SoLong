#include "minilibx/mlx.h"
#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int key_code, t_wlx *wlx)
{
	if (key_code == 53)
		mlx_destroy_window(wlx->mlx, wlx->win);
	exit (0);
}

int main()
{
	t_wlx	wlx;
	t_data	img;

	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, 3840, 2160, "Hello world!");
	img.img = mlx_new_image(wlx.mlx, 3840, 2160);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			//if (i == 99 || i == 0 || j == 99 || j == 0)
			//{
				my_mlx_pixel_put(&img, i, j, rgb_hex(i % 255, i * j % 255, j % 255));
			//}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(wlx.mlx, wlx.win, img.img, 0, 0);
	//mlx_hook(wlx.win, 2, 1L<<0, close, &wlx);
	mlx_key_hook(wlx.win, close, &wlx);
	mlx_loop(wlx.mlx);
}