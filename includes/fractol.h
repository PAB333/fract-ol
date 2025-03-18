/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:56:55 by pibreiss          #+#    #+#             */
/*   Updated: 2025/03/18 11:48:59 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define SIZE_X 800
# define SIZE_Y 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define NEON_GREEN 0x39FF14
# define NEON_PINK 0xFF6EC7
# define NEON_BLUE 0x1F51FF
# define NEON_YELLOW 0xFFFF33
# define NEON_ORANGE 0xFF5F1F
# define NEON_PURPLE 0x9D00FF
# define NEON_RED 0xFF073A
# define NEON_CYAN 0x00FFFF
# define NEON_MAGENTA 0xFF00FF
# define NEON_LIME 0xBFFF00
# define NEON_TURQUOISE 0x40E0D0
# define NEON_VIOLET 0x8F00FF
# define NEON_AQUA 0x00FFFF
# define NEON_CORAL 0xFF7F50

typedef struct s_img
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
	double	esc_value;
	int		definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_scaling_values
{
	double	unscale_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}				t_scaling_values;

//fractal initialization
void		fractal_initialization(t_fractal *fractal);

//render
void		fractal_render(t_fractal *fractal);

//string utils
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		string_to_double(char *str);

//math utils
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		scaling(t_scaling_values v);
double		scaling_values_1(t_scaling_values v, int x);
double		scaling_values_2(t_scaling_values v, int y);
double		scaling_values_3(t_scaling_values v, t_fractal *f, int i);

//events
int			key_manage(int keysym, t_fractal *fractal);
int			x_manage(t_fractal *fractal);
int			mouse_manage(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif