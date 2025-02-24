/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:53:55 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/24 23:46:41 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	manage_pixel(int x, int y, t_fractal *fractal)
{
	t_complex			z;
	t_complex			c;
	int					i;
	int					clr;
	t_scaling_values	v;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (scaling_values_1(v, x) * fractal->zoom) + fractal->shift_x;
	c.y = (scaling_values_2(v, y) * fractal->zoom) + fractal->shift_y;
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->esc_value)
		{
			clr = scaling_values_3(v, fractal, i);
			pixel_put(x, y, &fractal->img, clr);
			return;
		}
		++i;
	}
	pixel_put(x, y, &fractal->img, BLACK);
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
