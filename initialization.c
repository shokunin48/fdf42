/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:28:03 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 21:20:58 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_fdf *data)
{
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->zoom_height = 1;
	data->win_width = 1000;
	data->win_height = 2000;
	data->zoom = 50;
	data->begin_point_x = 700;
	data->begin_point_y = 260;
	data->angle = 0.9;
}
