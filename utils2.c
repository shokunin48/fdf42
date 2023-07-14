/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:32:25 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 19:48:23 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill(int x, int y, t_fdf *data)
{
	data->x = x;
	data->y = y;
}

void	z_put(t_fdf *data)
{
	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z1 = data->matrix[(int)data->y1][(int)data->x1];
}

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
	return (1);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y < data->win_height
		&& x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	rotations(t_fdf *data)
{
	rotate_x(&data->y, &data->z, data->x_angle);
	rotate_x(&data->y1, &data->z1, data->x_angle);
	rotate_y(&data->x, &data->z, data->y_angle);
	rotate_y(&data->x1, &data->z1, data->y_angle);
	rotate_z(&data->x, &data->y, data->z_angle);
	rotate_z(&data->x1, &data->y1, data->z_angle);
}
