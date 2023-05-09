/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:57:36 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 10:46:08 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "error.h"
#include <stdio.h>

t_map	*map_set(void)
{
	t_map	*map;

	map = (t_map *)malloczero(sizeof(t_map));
	if (!(map))
		force_quit(MAP_SET);
	map->width = 0;
	map->height = 0;
	map->coord = NULL;
	map->colors = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	return (map);
}

t_fdf	*fdf_set(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloczero(sizeof(t_fdf));
	if (!fdf)
		force_quit(FDF_SET);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		force_quit(FDF_SET);
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FdF");
	if (!fdf->win)
		force_quit(FDF_SET);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		force_quit(FDF_SET);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloczero(sizeof(t_mouse));
	if (!fdf->mouse)
		force_quit(FDF_SET);
	return (fdf);
}

t_camera	*camera_set(t_fdf *fdf)
{
	t_camera	*camera;
	int			a;
	int			b;

	a = (WIDTH - MENU) / fdf->map->width / 2;
	b = HEIGHT / fdf->map->height / 2;
	camera = (t_camera *)malloczero(sizeof(t_camera));
	if (!camera)
		force_quit(CAM_SET);
	if (a < b)
		camera->scale = a;
	else
		camera->scale = b;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
