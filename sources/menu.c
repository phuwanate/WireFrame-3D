#include "../includes/fdf.h"
#include "../mlx/mlx.h"
#include "../includes/color.h"

void	put_menu(t_fdf *fdf)
{
	int	y;
	int	*mlx;
	int	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;

	mlx_string_put(mlx, win, 65, y += 20, TEXT, "Control Guide");
	mlx_string_put(mlx, win, 15, y += 35, TEXT, "Scale x, y: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT, "Translate: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT, "Altitude: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT, "X-Axis - 1(+)/2(-)");
	mlx_string_put(mlx, win, 57, y += 25, TEXT, "Y-Axis - 3(+)/4(-)");
	mlx_string_put(mlx, win, 57, y += 25, TEXT, "Z-Axis - 5(+)/6(-)");
	mlx_string_put(mlx, win, 15, y += 30, TEXT, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT, "Parallel: P Key");
}
