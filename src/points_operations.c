/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:53:58 by macote            #+#    #+#             */
/*   Updated: 2023/04/07 11:13:55 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate(t_setting fdf, int i)
{
	t_rot_vars	r;

	r.y_prime = fdf.points[i].y * cos(fdf.x_rot) - fdf.points[i].z
		* sin(fdf.x_rot);
	r.z_prime = fdf.points[i].y * sin(fdf.x_rot) + fdf.points[i].z
		* cos(fdf.x_rot);
	fdf.points[i].y = (int)r.y_prime;
	fdf.points[i].z = (int)r.z_prime;
	r.x_prime = fdf.points[i].x * cos(fdf.y_rot) + fdf.points[i].z
		* sin(fdf.y_rot);
	r.z_prime = -1 * fdf.points[i].x * sin(fdf.y_rot) + fdf.points[i].z
		* cos(fdf.y_rot) + 0.5;
	fdf.points[i].x = (int)r.x_prime;
	fdf.points[i].z = (int)r.z_prime;
	r.x_prime = fdf.points[i].x * cos(fdf.z_rot) - fdf.points[i].y
		* sin(fdf.z_rot) + 0.5;
	r.y_prime = fdf.points[i].x * sin(fdf.z_rot) + fdf.points[i].y
		* cos(fdf.z_rot) + 0.5;
	fdf.points[i].x = (int)r.x_prime;
	fdf.points[i].y = (int)r.y_prime;
}

static void	center_points(t_setting fdf, int i)
{
	float	center_x;
	float	center_y;

	center_x = (WIDTH / 2) + fdf.center_x + 0.5;
	center_y = (HEIGHT / 2) - (2 * fdf.dim_y) + fdf.center_y + 0.5;
	fdf.points[i].x += (int)center_x;
	fdf.points[i].y += (int)center_y;
}

static void	apply_zoom(t_setting fdf, int i)
{
	fdf.points[i].x *= fdf.zoom;
	fdf.points[i].y *= fdf.zoom;
	fdf.points[i].z *= fdf.zoom;
}

void	points_operations(t_setting fdf)
{
	int	i;

	i = 0;
	while (fdf.points[i].enabled)
	{
		apply_zoom(fdf, i);
		rotate(fdf, i);
		if (fdf.projection_type == 0)
			points_to_isometric(fdf, i);
		else
			points_to_parallel(fdf, i);
		center_points(fdf, i);
		i++;
	}
}
