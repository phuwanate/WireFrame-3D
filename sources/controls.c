#include "../includes/fdf.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	close_win(void *param)
{
	(void)param;
	exit (0);
}

void	control(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_update, fdf);
}
