/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:53:19 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/25 20:29:58 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <unistd.h>
#include <math.h>

int	draw(t_vars *vars)
{
	int		x;
	int		y;
	int		color;
	int		maxiterations;

	maxiterations = 100;
	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = the_color(x, y, 100, vars);
			my_mlx_pixel_put(vars->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image->img, 0, 0);
	return (0);
}

#include<stdio.h>
//	#define LEFT 123
//	#define RIGHT 124
//	#define TOP 126
//	#define BOTTOM 125
//	int key(int key, t_vars *vars)
//	{
//		if (key == LEFT)
//			vars->origin.x -= 25;
//		else if (key == RIGHT)
//			vars->origin.x += 25;
//		else if (key == TOP)
//			vars->origin.y -= 25;
//		else if (key == BOTTOM)
//			vars->origin.y += 25;
//		else
//
//		{
//			printf("%d", key);
//			return 0;
//		}
//		draw(vars);
//		return 1;
//	}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_img	image;
	t_cord	julia;

	(void) av;
	vars.julia = NULL;
	vars.origin.x = 0;
	vars.origin.y = 0;
	vars.burn = 1;
	if (ac == 2)
		vars.julia = &julia;
	julia.x = 0.7;
	julia.y = 0.4;

	vars.range = 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, WIDTH, "fractol");
	vars.image = &image;
	vars.image->img = mlx_new_image(vars.mlx, WIDTH, WIDTH);
	vars.image->addr = mlx_get_data_addr(
			vars.image->img,
			&vars.image->bits_per_pixel,
			&vars.image->line_length,
			&vars.image->endian);
	mlx_hook(vars.win, 12, 0, draw, &vars);
	mlx_hook(vars.win, 6, 0, motion, &vars);
	mlx_mouse_hook(vars.win, zoom, &vars);
	mlx_key_hook(vars.win, key, &vars);

	mlx_loop(vars.mlx);
	return (0);
}
