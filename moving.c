/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:37:45 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/13 19:48:55 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift(int button, t_fdf *data)
{
	if (button == 126)
		data->shift_y -= 10;
	if (button == 125)
		data->shift_y += 10;
	if (button == 124)
		data->shift_x += 10;
	if (button == 123)
		data->shift_x -= 10;
	drawing_map(data);
}

void	zoom(int button, t_fdf *data)
{
	if (button == 12)
		data->zoom += 1;
	if (button == 14)
	{
		if (data->zoom - 1 < 0)
			return ;
		data->zoom -= 1;
	}
	drawing_map(data);
}

void	zoom_height_change(int button, t_fdf *data)
{
	if (button == 6)
		data->zoom_height += 0.1;
	if (button == 7)
		data->zoom_height -= 0.1;
	drawing_map(data);
}

void	change_angle(int button, t_fdf *data)
{
	if (button == 15)
		data->z_angle -= 0.05;
	if (button == 17)
		data->z_angle += 0.05;
	if (button == 3)
		data->x_angle -= 0.05;
	if (button == 5)
		data->x_angle += 0.05;
	if (button == 9)
		data->y_angle -= 0.05;
	if (button == 11)
		data->y_angle += 0.05;
	drawing_map(data);
}

int	keyboard(int button, t_fdf *data)
{
	if (button == 126 || button == 125 || button == 124 || button == 123)
		shift(button, data);
	if (button == 12 || button == 14)
		zoom(button, data);
	if (button == 6 || button == 7)
		zoom_height_change(button, data);
	if (button == 15 || button == 17 || button == 3
		|| button == 5 || button == 9 || button == 11)
		change_angle(button, data);
	if (button == 53)
		escape(data);
	return (0);
}
