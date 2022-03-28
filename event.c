/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:06:55 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/28 14:04:21 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	motion(int x, int y, t_vars *vars)
{
	if (vars->julia == NULL)
		return (0);
	if (vars->animation == 0)
		return (0);
	vars->julia->x = ft_map(x, -.6, .4);
	vars->julia->y = ft_map(y, -.6, .4);
	draw(vars);
	return (1);
}

int	key(int key, t_vars *vars)
{
	if (key == A_KEY)
		vars->animation = !vars->animation;
	if (key == LEFT)
		vars->origin.x -= 25;
	else if (key == RIGHT)
		vars->origin.x += 25;
	else if (key == TOP)
		vars->origin.y -= 25;
	else if (key == BOTTOM)
		vars->origin.y += 25;
	else if (key == ESC)
		exit(0);
	else
		return (0);
	draw(vars);
	return (1);
}

int	keypress(int keycode, t_vars *vars)
{
	(void)vars;
	ft_putnbr(keycode);
	write(1, "\n", 1);
	return (0);
}

int	destroy_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
