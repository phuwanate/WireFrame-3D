/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:38:17 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/04 17:48:33 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "../includes/color.h"

static void	get_background(t_fdf *fdf)
{
	int		*background;
	size_t	i;
	size_t	size;

	size = WIDTH * HEIGHT;
	ft_bzero(fdf->data_addr, size * (fdf->bits_per_pixel / 8));
	background = (int *)(fdf->data_addr);
	i = 0;
	while (i < size)
	{
		if (i % size < MENU)
			background[i] =  MENU_BACKGROUND;
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
				draw_line(plot_xyz(new_point(x, y, map), fdf),
					plot_xyz(new_point(x + 1, y, map), fdf), fdf);
		}
	}
}
