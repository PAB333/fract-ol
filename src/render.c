/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:53:55 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/21 03:43:35 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

void	fill_scaling_values1(t_scaling_values *s, int x)
{
	s->new_max = 2;
	s->new_min = -2;
	s->old_max = size_x;
	s->old_min = 0;
	s->unscale_num = x;
}

void	fill_scaling_values2(t_scaling_values *s, int y)
{
	s->unscale_num = y;
	s->old_max = size_y;
	s->new_max = -2;
	s->new_min = 2;
}

void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * img->bits_per_pixel / 8 );
	*(unsigned int *)(img->img_ptr + offset) = color;
}

void	manage_pixel(int x, int y, t_fractal *fractal)
{
	t_complex			z;
	t_complex			c;
	t_scaling_values	s;
	int					i;
	int					clr;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	fill_scaling_values1(&s, x);
	c.x = scaling(s);
	fill_scaling_values1(&s, y);
	c.y = scaling(s);
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x + z.x) + (z.y + z.y) > fractal->esc_value)
		{
			clr = (BLACK - WHITE) * (i - 0) / (fractal->definition - 0) + WHITE;
			pixel_put(x, y, &fractal->img, clr);
			return;
		}
		i++;
	}
	pixel_put(x, y, &fractal->img, NEON_RED);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			manage_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
			fractal->img.img_ptr, 0, 0);
}
