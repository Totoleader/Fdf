/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:05:24 by macote            #+#    #+#             */
/*   Updated: 2023/03/29 14:03:34 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ui_instructions(mlx_t *mlx)
{
	int	newline;
	int	x;
	int	y;
	int	i;

	newline = 25;
	x = WIDTH / 30;
	y = HEIGHT / 20;
	i = 0;
	mlx_put_string(mlx, "Exit:          ESQ", x, y + (i++ *newline));
	i++;
	mlx_put_string(mlx, "Move:          WASD", x, y + (i++ *newline));
	mlx_put_string(mlx, "Zoom:          scroll", x, y + (i++ *newline));
	mlx_put_string(mlx, "Rotate X:      SHIFT + UP/DOWN", x, y + (i++
			*newline));
	mlx_put_string(mlx, "Rotate Y:      UP/DOWN", x, y + (i++ *newline));
	mlx_put_string(mlx, "Rotate Z:      LEFT/RIGHT", x, y + (i++ *newline));
	mlx_put_string(mlx, "Enable cross:  X", x, y + (i++ *newline));
	mlx_put_string(mlx, "Points mode:   P", x, y + (i++ *newline));
	mlx_put_string(mlx, "Reset screen:  C", x, y + (i++ *newline));
	mlx_put_string(mlx, "Change vue:    V", x, y + (i++ *newline));
	mlx_put_string(mlx, "Change color:  Q", x, y + (i++ *newline));
}

void	draw_cross(t_setting fdf)
{
	int	i;

	i = 2;
	while (i < HEIGHT - 1)
	{
		mlx_put_pixel(fdf.img, WIDTH / 2, i, 0x2a2a2aFF);
		i++;
	}
	i = 2;
	while (i < WIDTH - 1)
	{
		mlx_put_pixel(fdf.img, i, HEIGHT / 2, 0x2a2a2aFF);
		i++;
	}
}
