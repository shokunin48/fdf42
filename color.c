/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:30:45 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/16 15:16:50 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color(t_fdf *data)
{
	if (data->z >= 2 || data->z1 >= 2)
		data->color = 0x0000FF;
	else if (data->z >= 1 || data->z1 >= 1)
		data->color = 0xFF9900;
	else if (data->z >= 3 || data->z1 >= 3)
		data->color = 0xA64D79;
	else if (data->z >= 5 || data->z1 >= 5)
		data->color = 0xFFFF00;
	else if (data->z >= 10 || data->z1 >= 10)
		data->color = 0xFF9900;
	else if (data->z <= 0 || data->z1 <= 0)
		data->color = 0x674EA7;
	else
		data->color = 0x00FFFF;
}

void	put_color(t_fdf *data)
{
	if (data->color_matrix[data->y][data->x])
		data->color = data->color_matrix[data->y][data->x];
	else
		check_color(data);
}

int	get_decimal(char hex)
{
	int	i;

	i = 0;
	while ("0123456789abcdef"[i] != hex && "0123456789ABCDEF"[i] != hex)
		i++;
	return (i);
}

int	get_color(char *temp)
{
	int	i;
	int	tem;
	int	color;
	int	counter;

	color = 0;
	counter = 0;
	i = 1;
	temp = ft_strnstr(temp, "0x", 8);
	if (temp != 0)
	{
		temp += 2;
		counter = ft_strlen(temp);
		if (ft_strnstr(temp, "\n", 8))
			counter -= 1;
		while (counter > 0)
		{
			tem = get_decimal(temp[--counter]);
			tem *= i;
			color += tem;
			i *= 16;
		}
	}
	return (color);
}
