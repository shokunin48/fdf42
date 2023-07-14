/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:57:34 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 20:10:21 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing_line(t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	x;
	float	y;

	x = (float)data->x;
	y = (float)data->y;
	x_step = (int)data->x1 - x;
	y_step = (int)data->y1 - y;
	max = max_nmb(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data->x1 - x) || (int)(data->y1 - y))
	{
		my_mlx_pixel_put(data, data->begin_point_x + x,
			data->begin_point_y + y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	drawing_map(t_fdf *data)
{
	int	x;
	int	y;

	if (data->img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		data->img = mlx_new_image(data->mlx_ptr, data->win_width,
				data->win_height);
	}
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
