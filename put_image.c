#include "header.h"

void *put_image(t_image image)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.win, image.img, image.x, image.y);
	return (image.img);
}