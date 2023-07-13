/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:04:26 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/13 15:59:51 by ibellash         ###   ########.fr       */
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

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
	{
		height++;
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
	width = 0;
	line = get_next_line(fd);
	width = nmb_words(line, ' ');
	free(line);
	close (fd);
	return (width);
}

void	fill_matrix(int *matrix_line, char *line)
{
	char	**nmbs;
	int		i;

	nmbs = ft_split(line, ' ');
	i = 0;
	while (nmbs[i])
	{
		matrix_line[i] = ft_atoi(nmbs[i]);
		free(nmbs[i]);
		i++;
	}
	free(nmbs);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i], line);
		i++;
		free(line);
	}
	close(fd);
	data->matrix[i] = NULL;
}
