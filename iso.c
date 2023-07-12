/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:37:09 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 21:21:09 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_x(float x, float y, t_fdf *data)
{
	fill(x, y, data);
	data->x1 = x + 1;
	data->y1 = y;
	color_check(data);
	zoom_pixels(data);
	shift_pixel_x(&data->x, &data->x1, data);
	shift_pixel_y(&data->y, &data->y1, data);
	rotate_x(&data->y, &data->z, data->x_angle);
	rotate_x(&data->y1, &data->z1, data->x_angle);
	rotate_y(&data->x, &data->z, data->y_angle);
	rotate_y(&data->x1, &data->z1, data->y_angle);
	rotate_z(&data->x, &data->y, data->z_angle);
	rotate_z(&data->x1, &data->y1, data->z_angle);
	isometric(&data->x, &data->y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	drawing_line(data);
}

void	iso_y(float x, float y, t_fdf *data)
{
	fill(x, y, data);
	data->x1 = x;
	data->y1 = y + 1;
	color_check(data);
	zoom_pixels(data);
	shift_pixel_x(&data->x, &data->x1, data);
	shift_pixel_y(&data->y, &data->y1, data);
	rotate_x(&data->y, &data->z, data->x_angle);
	rotate_x(&data->y1, &data->z1, data->x_angle);
	rotate_y(&data->x, &data->z, data->y_angle);
	rotate_y(&data->x1, &data->z1, data->y_angle);
	rotate_z(&data->x, &data->y, data->z_angle);
	rotate_z(&data->x1, &data->y1, data->z_angle);
	isometric(&data->x, &data->y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	drawing_line(data);
}
