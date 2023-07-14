/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:14:43 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 20:03:14 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
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
	int		**color_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		win_width;
	int		win_height;
	int		begin_point_x;
	int		begin_point_y;
	float	angle;
	int		x;
	int		y;
	int		z;
	int		x1;
	int		y1;
	int		z1;
	double	zoom_height;
	double	z_angle;
	double	y_angle;
	double	x_angle;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		constant;
}	t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	drawing_line(t_fdf *data);
void	drawing_map(t_fdf *data);
int		keyboard(int botton, t_fdf *data);
void	init_vars(t_fdf *data);
int		key_hook(int keycode, t_fdf *data);
float	max_nmb(float a, float b);
float	mod(float a);
void	fill(int x, int y, t_fdf *data);
void	z_put(t_fdf *data);
void	iso_x(int x, int y, t_fdf *data);
void	iso_y(int x, int y, t_fdf *data);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	rotate_x(int *y, int *z, double alpha);
int		error(char *msg);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		escape(t_fdf *data);
void	rotations(t_fdf *data);
void	zoom_add(t_fdf *data);
void	put_color(t_fdf *data);
int		**malloc_matrix(int height, int width);
int		get_color(char *temp);

#endif
