/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:29:56 by macote            #+#    #+#             */
/*   Updated: 2023/04/07 11:18:02 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset(t_setting *fdf)
{
	fdf->center_x = 0;
	fdf->center_y = 0;
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->zoom = 30;
	fdf->is_points = false;
	fdf->cross_on = true;
	draw(fdf);
}

static void	change_colors(t_setting *fdf)
{
	fdf->color += 2;
	if (fdf->color >= 5)
		fdf->color = 0;
	draw(fdf);
}

static void	projection_type(t_setting *fdf)
{
	if (!fdf->projection_type)
		fdf->projection_type++;
	else
		fdf->projection_type--;
	reset(fdf);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_setting	*fdf;

	fdf = (t_setting *)param;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
		translate(keydata, fdf);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		change_rotation(keydata, fdf);
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		line_to_point(fdf);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		reset(fdf);
	else if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		enable_cross(fdf);
	else if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		change_colors(fdf);
	else if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		projection_type(fdf);
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
}

void	zoom_hook(double xdelta, double ydelta, void *param)
{
	t_setting	*fdf;

	xdelta = 0;
	fdf = (t_setting *)param;
	if (ydelta > 2)
		ydelta = 2;
	else if (ydelta < -2)
		ydelta = -2;
	fdf->zoom += 0.6 * fdf->zoom / 5 * ydelta;
	if (fdf->zoom <= 0.1)
		fdf->zoom = 0.1;
	else if (fdf->zoom > 10000)
		fdf->zoom = 10000;
	draw(fdf);
}
