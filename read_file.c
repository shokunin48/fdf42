/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:04:26 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/14 21:54:12 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nmb_words(char *s, char c)
{
	int		reset;
	size_t	i;

	reset = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && reset == 0)
		{
			i++;
			reset = 1;
		}
		else if (*s == c)
			reset = 0;
		s++;
	}
	return (i);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		error("Error while trying to read file.\n");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		error("Error while trying to read file.\n");
	width = 0;
	line = get_next_line(fd);
	width = nmb_words(line, ' ');
	free(line);
	close (fd);
	return (width);
}

void	fill_two_matrix(int *matrix_line, int *color_matrix_line, char *line)
{
	char	**str;
	int		i;

	str = ft_split(line, ' ');
	i = 0;
	while (str[i])
	{
		color_matrix_line[i] = get_color(str[i]);
		matrix_line[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = malloc_matrix(data->height, data->width);
	data->color_matrix = malloc_matrix(data->height, data->width);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		error("Error while trying to read file.\n");
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_two_matrix(data->matrix[i], data->color_matrix[i], line);
		i++;
		free(line);
	}
	close(fd);
	data->matrix[i] = NULL;
}
