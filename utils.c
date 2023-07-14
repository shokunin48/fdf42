/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:47:57 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 21:52:18 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max_nmb(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	zoom_add(t_fdf *data)
{
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->z *= data->zoom_height;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->z1 *= data->zoom_height;
}

int	**malloc_matrix(int height, int width)
{
	int	i;
	int	**data;

	i = 0;
	data = (int **)malloc(sizeof(int *) * (height + 1));
	i = 0;
	while (i < height)
		data[i++] = (int *)malloc(sizeof(int) * (width + 1));
	return (data);
}
