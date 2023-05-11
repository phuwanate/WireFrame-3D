/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:38:17 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/10 15:55:02 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "color.h"
#include "mlx.h"

static void	point_init(t_point *d, t_point *u, t_point p1, t_point p2)
{
	u->x = ft_ismin(p1.x, p2.x);
	u->y = ft_ismin(p1.y, p2.y);
	d->x = absolute(p2.x - p1.x);
	d->y = absolute(p2.y - p1.y);
}

static void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if ((x >= MENU) && (x < WIDTH) && (y >= 0) && (y < HEIGHT))
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

static void	draw_line(t_point p1, t_point p2, t_fdf *fdf)
{
	t_point	distance;
	t_point	update;
	t_point	cur;
	int		diff[2];

	point_init(&distance, &update, p1, p2);
	diff[0] = distance.x - distance.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		draw_pixel(fdf, cur.x, cur.y, get_color(cur, p1, p2, distance));
		diff[1] = diff[0] * 2;
		if (diff[1] > -distance.y)
		{
			diff[0] -= distance.y;
			cur.x += update.x;
		}
		if (diff[1] < distance.x)
		{
			diff[0] += distance.x;
			cur.y += update.y;
		}
	}
}

static void	get_background(t_fdf *fdf)
{
	int		*background;
	size_t	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	background = (int *)(fdf->data_addr);
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i % WIDTH < MENU)
			background[i] = MENU_BACKGROUND;
		else
			background[i] = AVAILABLE;
		i++;
	}
}

void	draw_map(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	get_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(plot_xyz(get_point(x, y, map), fdf),
					plot_xyz(get_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_line(plot_xyz(get_point(x, y, map), fdf),
					plot_xyz(get_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	put_menu(fdf);
}

//fdf_utils.c : get_point(), ft_ismin(), absolute()
//plot_pixel.c: plot_xyz()
//mlx.h: mlx_put_image_to_window()
//menu.c: put_menu()
//get_color.c: get_color()
//libft.h: ft_bzero