/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:37:03 by macote            #+#    #+#             */
/*   Updated: 2023/03/29 14:16:38 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_setting *fdf)
{
	reset_screen(*fdf);
	reset_points(*fdf);
	points_operations(*fdf);
	if (fdf->cross_on == true)
		draw_cross(*fdf);
	if (fdf->is_points == false)
		draw_all_lines(*fdf);
	else if (fdf->is_points == true)
		draw_points(*fdf);
}

void	change_rotation(mlx_key_data_t keydata, t_setting *fdf)
{
	if (keydata.modifier == MLX_SHIFT && keydata.key == MLX_KEY_UP)
		fdf->x_rot += 0.04;
	else if (keydata.modifier == MLX_SHIFT && keydata.key == MLX_KEY_DOWN)
		fdf->x_rot -= 0.04;
	else if (keydata.key == MLX_KEY_UP)
		fdf->y_rot += 0.04;
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->y_rot -= 0.04;
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->z_rot += 0.04;
	else if (keydata.key == MLX_KEY_LEFT)
		fdf->z_rot -= 0.04;
	else
		return ;
	draw(fdf);
}

void	line_to_point(t_setting *fdf)
{
	if (fdf->is_points == false)
		fdf->is_points = true;
	else if (fdf->is_points == true)
		fdf->is_points = false;
	draw(fdf);
}

void	enable_cross(t_setting *fdf)
{
	if (fdf->cross_on == false)
		fdf->cross_on = true;
	else if (fdf->cross_on == true)
		fdf->cross_on = false;
	draw(fdf);
}

void	translate(mlx_key_data_t keydata, t_setting *fdf)
{
	if (keydata.key == MLX_KEY_W)
	{
		fdf->center_y -= fdf->zoom / 2;
		draw(fdf);
	}
	else if (keydata.key == MLX_KEY_S)
	{
		fdf->center_y += fdf->zoom / 2;
		draw(fdf);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		fdf->center_x += fdf->zoom / 2;
		draw(fdf);
	}
	else if (keydata.key == MLX_KEY_A)
	{
		fdf->center_x -= fdf->zoom / 2;
		draw(fdf);
	}
}
