/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:02:58 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/25 19:10:45 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

int	x_manage(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_manage(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		x_manage(fractal);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->definition += 10;
	else if (keysym == XK_minus)
		fractal->definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_manage(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	t_scaling_values	v;

	if (ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (scaling_values_1(v, x) * fractal->zoom)
				+ fractal->shift_x;;
		fractal->julia_y = (scaling_values_2(v, y) * fractal->zoom)
				+ fractal->shift_y;;
	}
	fractal_render(fractal);
	return (0);
}