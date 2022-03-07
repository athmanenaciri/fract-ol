/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:16:00 by anaciri           #+#    #+#             */
/*   Updated: 2022/02/20 15:29:07 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fractol.h"
#include <stdio.h>


typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;



typedef struct vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	
} t_vars;



void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;
	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int		redraw(t_vars  *vars)
{
	int i = 50;
	while (i <= 200)
	{
		my_mlx_pixel_put(&vars->img, 50, 100, 0xffffff);
		i++;
	}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	return(0);
}



int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "naciri's fractol");
	mlx_hook(vars.win, 12, 1, redraw, &vars);

	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,&vars.img.endian);
	my_mlx_pixel_put(&vars.img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
