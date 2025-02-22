/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:00:01 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/22 20:49:26 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

double	scaling_values_1(t_scaling_values v, int x)
{
	v.new_max = +2;
	v.new_min = -2;
	v.old_max = size_x;
	v.old_min = 0;
	v.unscale_num = x;
	return (scaling(v));
}

double	scaling_values_2(t_scaling_values v, int y)
{
	v.new_max = -2;
	v.new_min = +2;
	v.old_max = size_y;
	v.old_min = 0;
	v.unscale_num = y;
	return (scaling(v));
}

double	scaling_values_3(t_scaling_values v, t_fractal f, int i)
{
	v.new_max = WHITE;
	v.new_min = BLACK;
	v.old_max = f.definition;
	v.old_min = 0;
	v.unscale_num = i;
	return (scaling(v));
}