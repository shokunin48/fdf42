/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:14:55 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 20:28:39 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	escape(t_fdf *data)
{
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = (t_fdf *) malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	init_vars(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_height, data->win_width, "FDF");
	drawing_map(data);
	mlx_key_hook(data->win_ptr, keyboard, data);
	mlx_hook(data->win_ptr, 17, 0, escape, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
