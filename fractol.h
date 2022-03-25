/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:51:11 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/25 20:29:51 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 500
# define ESC 53

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct point
{
	double	x;
	double	y;
}	t_cord;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	double	range;
	t_img	*image;
	t_cord	*julia;
	t_cord	origin;

	int burn;

}	t_vars;

int		zoom(int key, int x, int y, t_vars *vars);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	ft_map(double n, double f2, double t2);
int		draw(t_vars *vars);
int		motion(int x, int y, t_vars *vars);
int		the_color(int x, int y, int maxiterations, t_vars *vars);
int key(int key, t_vars *vars);

#endif
