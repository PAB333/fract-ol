/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:50:42 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/20 20:27:31 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)) 
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		fractal_initialization(&fractal);
		//fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Argument error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
