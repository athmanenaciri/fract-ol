/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:44:22 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/25 17:31:08 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_map(double n, double f2, double t2)
{
	return (f2 + (n - 0) * ((t2 - f2) / (500 - 0)));
}

int	the_color(int x, int y, int maxiterations, t_vars *vars)
{
	int		color;
	int		n;
	t_cord	c;
	t_cord	dos;
	t_cord	cord;

	cord.x = ft_map (vars->origin.x + x, -vars->range, vars->range);
	cord.y = ft_map (vars->origin.y + y, -vars->range, vars->range);
	if (vars->julia)
	{
		c.x = vars->julia->x;
		c.y = vars->julia->y;
	}
	else
	{
		c.x = cord.x;
		c.y = cord.y;
	}
	n = 0;
	color = 0;
	while (n < maxiterations)
	{
		dos.x = cord.x * cord.x - cord.y * cord.y;
		if (vars->burn == 1)
			dos.y = fabs(2 * cord.x * cord.y);
		else
			dos.y = 2 * cord.x * cord.y;
		cord.x = dos.x + c.x;
		cord.y = dos.y + c.y;
		n++;
		if (cord.x * cord.x + cord.y * cord.y > 4)
		{
			color = 0xf4f4f5;
			return (color * n);
		}
	}
	return (color);
}
