/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:32:25 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 20:35:35 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill(int x, int y, t_fdf *data)
{
	data->x = x;
	data->y = y;
}

void	color_check(t_fdf *data)
{
	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z1 = data->matrix[(int)data->y1][(int)data->x1];
	data->color = get_color(data->z);
	data->color = get_color(data->z1);
}
