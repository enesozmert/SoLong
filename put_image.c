/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:04:41 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 12:05:10 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*put_image(t_image image)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, image.relative_path,
			&image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.win,
		image.img, image.x, image.y);
	return (image.img);
}
