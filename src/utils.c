/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:48 by macote            #+#    #+#             */
/*   Updated: 2023/03/29 14:23:38 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_dimensions(mlx_instance_t *point, int *dim_x, int *dim_y)
{
	int	i;

	i = 0;
	while (point[i].enabled)
		i++;
	*dim_x = point[i - 1].x + 1;
	*dim_y = point[i - 1].y + 1;
}

void	reset_points(t_setting fdf)
{
	int	nb_of_points;

	nb_of_points = (fdf.dim_x * fdf.dim_y + 1) * sizeof(*fdf.points_init);
	ft_memcpy(fdf.points, fdf.points_init, nb_of_points);
}

void	reset_screen(t_setting fdf)
{
	size_t	screen_size;

	screen_size = fdf.img->width * fdf.img->height * sizeof(int32_t);
	ft_bzero(&fdf.img->pixels, screen_size);
}
