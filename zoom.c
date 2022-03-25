/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:43:12 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/25 20:30:16 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h> 

void	zoom_in(t_vars *vars)
{
	vars->range -= vars->range * .1;
}

void	zoom_out(t_vars *vars)
{
	vars->range += vars->range * .1;
}

int	zoom(int key, int x, int y, t_vars *vars)
{
	x = y;
	if (key == 5)
		zoom_in(vars);
	else if (key == 4)
		zoom_out(vars);
	draw(vars);
	return (1);
}

int	motion(int x, int y, t_vars *vars)
{
	if (vars->julia == NULL)
		return (0);
	vars->julia->x = ft_map(x, -.6, .4);
	vars->julia->y = ft_map(y, -.6, .4);
	draw(vars);
	return (1);
}


#define LEFT 123
#define RIGHT 124
#define TOP 126
#define BOTTOM 125
#define ESC 53
int key(int key, t_vars *vars)
{
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
	{
		printf("%d", key);
		return 0;
	}

	draw(vars);
	return 1;
}
