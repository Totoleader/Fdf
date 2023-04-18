/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:29:43 by macote            #+#    #+#             */
/*   Updated: 2023/04/03 11:20:04 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_error(void)
{
	exit(EXIT_FAILURE);
}

void	set_window(mlx_t **mlx, mlx_image_t **img)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	*mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!mlx)
		ft_error();
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(*mlx, *img, 0, 0) < 0))
		ft_error();
	ui_instructions(*mlx);
}
