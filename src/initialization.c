/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:02:12 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/25 19:25:49 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

void	malloc_error(void)
{
	ft_putstr_fd("Error with Malloc\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	event_initialization(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_manage, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_manage, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, x_manage, fractal);
}

void	data_initialization(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->definition = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	fractal_initialization(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, size_x,
			size_y, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, size_x,
			size_y);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
	event_initialization(fractal);
	data_initialization(fractal);
}
