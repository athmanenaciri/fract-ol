/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:31:17 by zachaaib          #+#    #+#             */
/*   Updated: 2022/03/07 18:06:03 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<mlx.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;
	
int draw(t_vars *vars)
{
	int x = 100;
	int y = 0;
	unsigned int b = 0x0000ff;
	unsigned int w = 0xffffff;
	unsigned int r = 0xff0000;
	unsigned int here;
	while (x < 800)
	{
		y = 0;
		while (y < 800)
		{
			y++;	
		}
		x++;
	}
	//printf("ISMAIL");
	//fflush(stdout);
	return(1);
}

int keypress(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	return (0);
}




int main()
{
	t_vars vars;

	//void *mlx =  mlx_init();
	vars.mlx =  mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "NEWWINDOW");
	mlx_hook(vars.win, 12, 0, draw, &vars);
	mlx_hook(vars.win, 2, 0, keypress, &vars);

	mlx_loop(vars.mlx);
}
