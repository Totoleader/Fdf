/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:37:29 by macote            #+#    #+#             */
/*   Updated: 2023/04/07 11:42:45 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf_values(t_setting *fdf, int fd)
{
	fdf->zoom = 10;
	fdf->points_init = parse_to_struct(fd, &fdf->points);
	if (!fdf->points_init)
		return ;
	get_dimensions(fdf->points_init, &fdf->dim_x, &fdf->dim_y);
	fdf->points = ft_calloc(sizeof(mlx_instance_t), (fdf->dim_x * fdf->dim_y
				+ 1));
	reset_points(*fdf);
	fd = 0;
	fdf->cross_on = true;
	fdf->is_points = false;
	fdf->center_x = 0;
	fdf->center_y = 0;
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->color = 0;
	fdf->projection_type = 0;
	fdf->colors[0] = 0xF51720FF;
	fdf->colors[1] = 0xFF8E00FF;
	fdf->colors[2] = 0x9609bFF;
	fdf->colors[3] = 0x5697bbFF;
	fdf->colors[4] = 0x7ED615FF;
	fdf->colors[5] = 0xCCED32FF;
}

void	fdf(char *map)
{
	t_setting	fdf;
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("File not found.");
		return ;
	}
	init_fdf_values(&fdf, fd);
	if (!fdf.points_init)
		return ;
	set_window(&fdf.mlx, &fdf.img);
	draw_cross(fdf);
	points_operations(fdf);
	draw_all_lines(fdf);
	mlx_key_hook(fdf.mlx, key_hook, &fdf);
	mlx_scroll_hook(fdf.mlx, zoom_hook, &fdf);
	mlx_loop(fdf.mlx);
	free_struct(fdf);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	fdf(argv[1]);
	return (0);
}
