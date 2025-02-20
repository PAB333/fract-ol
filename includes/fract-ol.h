/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:56:55 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/20 20:27:03 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minilibx-linux/mlx.h"

#define size_x 800
#define size_y 800

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_fractal;


//fractal initialization
void	fractal_initialization(t_fractal *fractal);

//string utils
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);


#endif