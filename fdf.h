/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:14:43 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/12 21:27:56 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		win_width;
	int		win_height;
	int		begin_point_x;
	int		begin_point_y;
	float	angle;
	float	x;
	float	y;
	float	z;
	float	x1;
	float	y1;
	float	z1;
	double	zoom_height;
	double	z_angle;
	double	y_angle;
	double	x_angle;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	drawing_line(t_fdf *data);
void	drawing_map(t_fdf *data);
int		keyboard(int botton, t_fdf *data);
void	init_vars(t_fdf *data);
int		key_hook(int keycode, t_fdf *data);
float	max_nmb(float a, float b);
void	isometric(float *x, float *y, int z, t_fdf *data);
float	mod(float a);
void	zoom_pixels(t_fdf *data);
int		get_color(int z);
void	fill(int x, int y, t_fdf *data);
void	color_check(t_fdf *data);
void	iso_x(float x, float y, t_fdf *data);
void	iso_y(float x, float y, t_fdf *data);
void	shift_pixel_x(float *x, float *x1, t_fdf *data);
void	shift_pixel_y(float *y, float *y1, t_fdf *data);
void	rotate_y(float *x, float *z, double beta);
void	rotate_z(float *x, float *y, double gamma);
void	rotate_x(float *y, float *z, double alpha);

#endif
