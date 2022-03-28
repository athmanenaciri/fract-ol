/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:44:22 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/28 10:32:58 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	check(t_vars *vars, t_cord cord, t_cord *c)
{
	if (vars->julia)
	{
		c->x = vars->julia->x;
		c->y = vars->julia->y;
	}
	else
	{
		c->x = cord.x;
		c->y = cord.y;
	}
}

int	iterations(t_vars *vars, t_cord *cord, t_cord *dos, t_cord *c)
{
	int	n;
	int	maxiterations;

	n = 0;
	maxiterations = 100;
	while (n < maxiterations)
	{
		dos->x = cord->x * cord->x - cord->y * cord->y;
		if (vars->burn == 1)
			dos->y = fabs(2 * cord->x * cord->y);
		else
			dos->y = 2 * cord->x * cord->y;
		cord->x = dos->x + c->x;
		cord->y = dos->y + c->y;
		if (cord->x * cord->x + cord->y * cord->y > 4)
		{
			return (n);
		}
		n++;
	}
	return (n);
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
	check(vars, cord, &c);
	color = 0;
	n = iterations(vars, &cord, &dos, &c);
	if (n != maxiterations)
		color = 0xf4f4f5;
	return (color * n);
}
