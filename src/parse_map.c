/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:36:16 by macote            #+#    #+#             */
/*   Updated: 2023/04/07 11:41:37 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_count(char *line)
{
	int	i;
	int	count_lines;

	count_lines = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			count_lines++;
		i++;
	}
	return (count_lines);
}

int	count_matrix_elems(char ***matrix)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

mlx_instance_t	*matrix_to_struct(char ***matrix)
{
	int				i;
	int				j;
	int				k;
	mlx_instance_t	*point;

	point = ft_calloc(sizeof(*point), count_matrix_elems(matrix) + 1);
	if (!point)
		return (NULL);
	k = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			point[k].x = j;
			point[k].y = i;
			point[k].z = ft_atoi(matrix[i][j]);
			free(matrix[i][j++]);
			point[k++].enabled = true;
		}
		free(matrix[i++]);
	}
	free(matrix);
	return (point);
}

char	***str_to_matrix(char *string)
{
	int		nb_of_lines;
	char	***matrix;
	char	**lines;
	int		i;

	nb_of_lines = line_count(string);
	matrix = ft_calloc(sizeof(*matrix), nb_of_lines + 1);
	if (!matrix)
		return (NULL);
	lines = ft_split(string, '\n');
	i = 0;
	while (i < nb_of_lines)
	{
		matrix[i] = ft_split(lines[i], ' ');
		free(lines[i]);
		i++;
	}
	free(lines);
	return (matrix);
}

mlx_instance_t	*parse_to_struct(int fd, mlx_instance_t **point)
{
	char	buffer[1000];
	char	*string;
	int		read_check;
	int		i;

	string = NULL;
	read_check = read(fd, buffer, 1000);
	while (read_check > 0)
	{
		string = ft_strjoin(string, buffer, read_check);
		read_check = read(fd, buffer, 1000);
	}
	if (!string)
		return (perror("Empty file."), NULL);
	i = 0;
	while (string[i] && string[i + 1])
		i++;
	if (string[i] != '\n')
	{
		free(string);
		return (perror("Map must end with new line."), NULL);
	}
	*point = matrix_to_struct(str_to_matrix(string));
	free(string);
	return (*point);
}
