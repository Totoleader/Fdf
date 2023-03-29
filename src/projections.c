/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:55:28 by macote            #+#    #+#             */
/*   Updated: 2023/03/29 14:03:45 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	points_to_isometric(t_setting fdf, int i)
{
	float	x;
	float	y;

	x = fdf.points[i].x;
	y = fdf.points[i].y;
	x = (x - y) * cos(1) + 0.5;
	y = (x + y) * sin(1) - fdf.points[i].z + 0.5;
	fdf.points[i].x = (int)x;
	fdf.points[i].y = (int)y;
}

void	points_to_parallel(t_setting fdf, int i)
{
	float	x;
	float	y;

	x = fdf.points[i].x;
	y = fdf.points[i].y;
	x = x + 0.5 * fdf.points[i].z;
	y = y + 0.5 * fdf.points[i].z;
	fdf.points[i].x = (int)x;
	fdf.points[i].y = (int)y;
}
