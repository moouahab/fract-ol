/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:50 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:33:46 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	color_cyber(int x, int y)
{
	int	r;
	int	g;
	int	b;

	r = (x * y) % 255;
	g = (x + y) % 255;
	b = (x - y) % 255;
	return ((r << 16) | (g << 8) | b);
}

int	color_trgb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

void	render_background(t_mlx_data *data, t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		++i;
	}
}

void	bg_arc(t_mlx_data *data, t_img	*img)
{
	static int	i;

	if (!i)
		i = 0;
	if (i >= 0)
	{
		if (i < 250)
			render_background(data, img, color_trgb(0, 400, 0, 153));
		else if (i <= 500)
			render_background(data, img, color_trgb(0, 0, 203, 153));
		else if (i <= 700)
			render_background(data, img, color_trgb(0, 145, 33, 183));
		else if (i <= 1000)
		{
			if (i == 1000)
				i = 0;
			render_background(data, img, color_trgb(0, 15, 45, 183));
		}
		i++;
	}
}
