/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:53:55 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/22 00:43:06 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->img_ptr + offset) = color;
}

void	manage_pixel(int x, int y, t_fractal *fractal)
{
	t_complex			z;
	t_complex			c;
	int					i;
	int					clr;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (2 - (-2)) * x / size_x + (-2);
	c.y = ((-2) - 2) * y / size_y + 2;
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->esc_value)
		{
			clr = (BLACK - WHITE) * i / fractal->definition + WHITE;
			pixel_put(x, y, &fractal->img, clr);
			return;
		}
		++i;
	}
	pixel_put(x, y, &fractal->img, NEON_RED);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size_y)
	{
		x = -1;
		while (++x < size_x)
		{
			manage_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
			fractal->img.img_ptr, 0, 0);
}
