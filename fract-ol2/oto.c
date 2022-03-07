#include<math.h>
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
	int x = 50;
	double y = 50;

	unsigned int blue = 0x0000ff;
	unsigned int black = 0x000000;
	unsigned int w = 0xffffff;
	unsigned int r = 0xff0000;
	unsigned int yellow = 0xffd700;

	while(y <= 200)
	{
		while(x <= 250)
		{
			if(x <= 100)
				mlx_pixel_put(vars->mlx, vars->win, x++,y, yellow);
			if (x >= 200 && x <=250)
				mlx_pixel_put(vars->mlx, vars->win, x++,y, yellow);
			else
				mlx_pixel_put(vars->mlx, vars->win, x++,y, black);
		}
		y++;
	}



/*
		while(x <= 600 && y <= 600)
		{	
			while (x <= 600)
			{
				if (y <= 400)
					mlx_pixel_put(vars->mlx, vars->win, x++,y, blue);
				else
					mlx_pixel_put(vars->mlx, vars->win, x++,y, yellow);
			}
			x = 200;
			y++;
		}
	//printf("ISMAIL");
	//mlx_pixel_put(vars->mlx, vars->win, x++,y, yellow);
	//fflush(stdout);*/
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
