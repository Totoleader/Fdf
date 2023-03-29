/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:37:51 by macote            #+#    #+#             */
/*   Updated: 2023/03/29 14:18:27 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct draw_var_
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				bdx;
	int				bdy;
	int				ex;
	int				ey;
	int				i;
	int				x_incr;
	int				y_incr;
}					t_draw_var;

typedef struct rotation_vars
{
	float			x_prime;
	float			y_prime;
	float			z_prime;
}					t_rot_vars;

typedef struct fdf_settings
{
	float			zoom;
	float			x_rot;
	float			y_rot;
	float			z_rot;
	float			center_x;
	float			center_y;
	int				dim_x;
	int				dim_y;
	bool			is_points;
	bool			cross_on;
	bool			projection_type;
	unsigned int	colors[6];
	int				color;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_instance_t	*points;
	mlx_instance_t	*points_init;
}					t_setting;

mlx_instance_t		*parse_to_struct(int fd, mlx_instance_t **points);
void				draw_points(t_setting fdf);
void				points_operations(t_setting fdf);

void				get_dimensions(mlx_instance_t *points, int *dim_x,
						int *dim_y);
void				draw_all_lines(t_setting set);

void				key_hook(mlx_key_data_t keydata, void *param);

void				set_window(mlx_t **mlx, mlx_image_t **img);

void				reset_points(t_setting fdf);
void				reset_screen(t_setting fdf);

void				zoom_hook(double xdelta, double ydelta, void *param);

void				draw(t_setting *fdf);

void				draw_cross(t_setting fdf);

void				ui_instructions(mlx_t *mlx);

void				free_struct(t_setting fdf);

void				change_rotation(mlx_key_data_t keydata, t_setting *fdf);
void				line_to_point(t_setting *fdf);
void				enable_cross(t_setting *fdf);
void				translate(mlx_key_data_t keydata, t_setting *fdf);

void				points_to_isometric(t_setting fdf, int i);
void				points_to_parallel(t_setting fdf, int i);

#endif