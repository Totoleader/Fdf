/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:13:26 by macote            #+#    #+#             */
/*   Updated: 2023/03/29 14:19:20 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//draws points at the coordinates (no lines)
void	draw_points(t_setting fdf)
{
	int	i;
	int	dim;

	i = 0;
	dim = fdf.dim_x * fdf.dim_y;
	while ((i + 1) <= dim)
	{
		if (fdf.points[i].x > 0 && fdf.points[i].x < WIDTH
			&& fdf.points[i].y > 0 && fdf.points[i].y < HEIGHT)
			mlx_put_pixel(fdf.img, fdf.points[i].x, fdf.points[i].y,
				fdf.colors[fdf.color]);
		i++;
	}
}

//first bresenham algo case
static void	bresenham_case1(t_setting fdf, t_draw_var var)
{
	while (var.i <= var.bdx)
	{
		if (var.x > 0 && var.x < WIDTH && var.y > 0 && var.y < HEIGHT)
			mlx_put_pixel(fdf.img, var.x, var.y, fdf.colors[fdf.color]);
		var.i++;
		var.x += var.x_incr;
		var.ex -= var.dy;
		if (var.ex < 0)
		{
			var.y += var.y_incr;
			var.ex += var.dx;
		}
	}
}

//second bresenham algo case
static void	bresenham_case2(t_setting fdf, t_draw_var var)
{
	while (var.i <= var.bdy)
	{
		if (var.x > 0 && var.x < WIDTH && var.y > 0 && var.y < HEIGHT)
			mlx_put_pixel(fdf.img, var.x, var.y, fdf.colors[fdf.color + 1]);
		var.i++;
		var.y += var.y_incr;
		var.ey -= var.dx;
		if (var.ey < 0)
		{
			var.x += var.x_incr;
			var.ey += var.dy;
		}
	}
}

//draws a line between point i1 and i2
static void	draw_line_bresenham(t_setting fdf, int i1, int i2)
{
	t_draw_var	var;

	var.x = fdf.points[i1].x;
	var.y = fdf.points[i1].y;
	var.ex = abs(fdf.points[i2].x - var.x);
	var.ey = abs(fdf.points[i2].y - var.y);
	var.dx = 2 * var.ex;
	var.dy = 2 * var.ey;
	var.bdx = var.ex;
	var.bdy = var.ey;
	var.i = 0;
	var.x_incr = 1;
	var.y_incr = 1;
	if (var.x > fdf.points[i2].x)
		var.x_incr = -1;
	if (var.y > fdf.points[i2].y)
		var.y_incr = -1;
	if (var.dx >= var.dy)
	{
		bresenham_case1(fdf, var);
	}
	else if (var.dx < var.dy)
	{
		bresenham_case2(fdf, var);
	}
}

//decides where the lines should be drawn
void	draw_all_lines(t_setting fdf)
{
	int	i;
	int	dim;

	i = 0;
	dim = fdf.dim_x * fdf.dim_y;
	while ((i + 1) <= dim)
	{
		if ((i + 1) % fdf.dim_x != 0)
		{
			draw_line_bresenham(fdf, i, i + 1);
		}
		if ((i + 1) <= dim - fdf.dim_x)
		{
			draw_line_bresenham(fdf, i, i + fdf.dim_x);
		}
		i++;
	}
}
