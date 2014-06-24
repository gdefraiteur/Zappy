/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:15:04 by gdefrait          #+#    #+#             */
/*   Updated: 2014/04/27 14:15:06 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

t_img				pixel_put(t_img img, int x, int y, unsigned long color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF);
	img.data[y * img.sizeline + x * img.bits / 8] = b;
	img.data[y * img.sizeline + x * img.bits / 8 + 1] = g;
	img.data[y * img.sizeline + x * img.bits / 8 + 2] = r;
	return (img);
}

void				put_image(t_img img)
{
	mlx_put_image_to_window(img.ptr, img.win, img.img,
							img.pos_x, img.pos_y);
	return ;
}

t_img				create_img(t_img img)
{
	img.ptr = mlx_init();
	img.win = mlx_new_window(img.ptr, WINDOW_X, WINDOW_Y, "fdf");
	img.img = (char *)mlx_new_image(img.ptr, WINDOW_X, WINDOW_Y);
	img.data = mlx_get_data_addr(img.img,
	&img.bits, &img.sizeline, &img.endian);
	img.pos_x = 0;
	img.pos_y = 0;
	return (img);
}
