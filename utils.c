/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:47:57 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 21:16:54 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max_nmb(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	zoom_pixels(t_fdf *data)
{
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->z *= data->zoom_height;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->z1 *= data->zoom_height;
}

int	get_color(int z)
{
	if (z > 0)
		return (0xffd700);
	else if (z < 0)
		return (0x00ffff);
	return (0xffffff);
}
