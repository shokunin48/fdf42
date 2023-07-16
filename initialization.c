/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:28:03 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 22:04:01 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_fdf *data)
{
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->constant = 1;
	data->endian = 0;
	data->zoom_height = 1;
	data->win_width = 2000;
	data->win_height = 1000;
	data->angle = 0.9;
	if (data->win_width >= data->win_height)
		data->constant = data->win_width / data->win_height;
	data->zoom = data->win_width / data->width / 1.5 / data->constant;
	data->begin_point_x = data->win_width / 2 - data->width / 3;
	data->begin_point_y = data->win_height / 2 - data->height / 3 * data->zoom;
}
