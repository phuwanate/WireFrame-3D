#include "mlx/mlx.h"
#include <stdio.h>

int main()
{

	int x1 = 0;
	int x2 = 800;
	int y1 = 0;
	int y2 = 600;
	int x = x1;
	int y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;
	int p = (2*dy) - (2*dx);
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "mlx 42");

	while (x <= x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,x,y, 0x00FF00);
		x++;
		if(p < 0)
			p = p + (2 * dy);
		else
		{	
			p = p + (2 * dy) - (2 * dx);
			y++;
		}
	}
	y = 0;
	while (x >= 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,x,y, 0xFF0000);
		x--;
		if(p < 0)
			p = p + (2 * dy);
		else
		{	
			p = p + (2 * dy) - (2 * dx);
			y++;
		}
	}

	
	mlx_loop(mlx_ptr);
}
