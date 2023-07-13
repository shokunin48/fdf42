/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:14:55 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/13 17:47:34 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_2d_matrix(int **matrix, t_fdf *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	escape(t_fdf *data)
{
	mlx_destroy_window(data->win_ptr, data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->matrix)
		free_2d_matrix(data->matrix, data);
	free(data);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		error("!!Invalid number of arguments!!\n");
	data = (t_fdf *) malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	read_file(argv[1], data);
	init_vars(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	drawing_map(data);
	mlx_key_hook(data->win_ptr, keyboard, data);
	mlx_hook(data->win_ptr, 17, 0, escape, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
