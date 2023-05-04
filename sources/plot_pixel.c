/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:41:50 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/04 19:57:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "math.h"

static void	x_rotate(int *y, int *z, double alpha)
{
	int	old_y;

	old_y = *y;
	*y = old_y * cos(alpha) + *z * sin(alpha);
	*z = -old_y * sin(alpha) + *z * cos(alpha);
}

static void	y_rotate(int *x, int *z, double beta)
{
	int	old_x;

	old_x = *x;
	*x = old_x * cos(beta) + *z * sin(beta);
	*z = -old_x * sin(beta) + *z * cos(beta);
}

static void	z_rotate(int *x, int *y, double gamma)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(gamma) - old_y * sin(gamma);
	*y = old_x * sin(gamma) - old_y * cos(gamma);
}

t_point	plot_xyz(t_point point, t_fdf *fdf)
{
	point.x *= fdf->camera->scale;
	point.y *= fdf->camera->scale;
	point.z *= fdf->camera->scale / fdf->camera->z_height;
	point.x -= (fdf->map->width * fdf->camera->scale) / 2;
	point.y -= (fdf->map->height * fdf->camera->scale) / 2;
	x_rotate(&point.y, &point.z, fdf->camera->alpha);
	y_rotate(&point.x, &point.z, fdf->camera->beta);
	x_rotate(&point.x, &point.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISOMETRIC)
		iso(&point.x, &point.y, &pointz);
		
}