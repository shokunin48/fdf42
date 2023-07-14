/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:37:09 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 22:02:07 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x, int *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	iso_x(int x, int y, t_fdf *data)
{
	fill(x, y, data);
	data->x1 = x + 1;
	data->y1 = y;
	z_put(data);
	zoom_add(data);
	put_color(data);
	//rotations(data);
	isometric(&data->x, &data->y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	drawing_line(data);
}

void	iso_y(int x, int y, t_fdf *data)
{
	fill(x, y, data);
	data->x1 = x;
	data->y1 = y + 1;
	z_put(data);
	zoom_add(data);
	put_color(data);
	//rotations(data);
	isometric(&data->x, &data->y, data->z, data);
	isometric(&data->x1, &data->y1, data->z1, data);
	drawing_line(data);
}
