/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:57:34 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 21:27:44 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_pixel_x(float *x, float *x1, t_fdf *data)
{
	*x += data->shift_x;
	*x1 += data->shift_x;
}

void	shift_pixel_y(float *y, float *y1, t_fdf *data)
{
	*y += data->shift_y;
	*y1 += data->shift_y;
}

void	drawing_line(t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	x;
	float	y;

	x = data->x;
	y = data->y;
	x_step = (int)data->x1 - x;
	y_step = (int)data->y1 - y;
	max = max_nmb(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data->x1 - x) || (int)(data->y1 - y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->begin_point_x + x,
			data->begin_point_y + y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	drawing_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				iso_x(x, y, data);
			if (y < data->height - 1)
				iso_y(x, y, data);
			x++;
		}
		y++;
	}
}
