#include "mlx/mlx.h"
#include <stdio.h>

int main()
{
	int bpp;
	int size_line;
	int endian;
	int count_w = 0;
	int count_h = 0;
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "mlx 42");

	int	i = 0;
	while (i < 600)
	{
		int j = 0;
		while (j < 800)
		{
			if (i == j)
				mlx_pixel_put(mlx_ptr, win_ptr,j,i, 0x00FF00);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
	
}
