/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:37:45 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 21:27:03 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard(int botton, t_fdf *data)
{
	if (botton == 126) // arrows
		data->shift_y -= 10;
	if (botton == 125)
		data->shift_y += 10;
	if (botton == 124)
		data->shift_x += 10;
	if (botton == 123)
		data->shift_x -= 10;
	if (botton == 12) // q , e
		data->zoom += 10;
	if (botton == 14)
		data->zoom -= 10;
	if (botton == 6) // z , x
		data->zoom_height += 0.1;
	if (botton == 7)
		data->zoom_height -= 0.1;
	if (botton == 15) // r , t
		data->z_angle -= 0.1;
	if (botton == 17)
		data->z_angle += 0.1;
	if (botton == 3) // f , g
		data->x_angle -= 0.1;
	if (botton == 5)
		data->x_angle += 0.1;
	if (botton == 9) // v , b
		data->y_angle -= 0.1;
	if (botton == 11)
		data->y_angle += 0.1;
	if (botton == 53)
		exit (1);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drawing_map(data);
	return (0);
}
