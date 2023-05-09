/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:29:25 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 10:44:14 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int	default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_1);
	else if (percentage < 0.4)
		return (COLOR_2);
	else if (percentage < 0.6)
		return (COLOR_3);
	else if (percentage < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
}

static int	light_adjust(int start, int end, double percentage)
{
	int	result;

	result = (((1 - percentage) * start) + (percentage * end));
	return (result);
}

int	get_color(t_point cur, t_point start, t_point end, t_point distance)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (cur.colors == end.colors)
		return (cur.colors);
	if (distance.x > distance.y)
		percentage = percent(start.x, end.x, cur.x);
	else
		percentage = percent(start.y, end.y, cur.y);
	r = light_adjust((start.colors >> 16) & 0xFF,
			(end.colors >> 16) & 0xFF, percentage);
	g = light_adjust((start.colors >> 8) & 0xFF,
			(end.colors >> 8) & 0xFF, percentage);
	b = light_adjust(start.colors & 0xFF,
			end.colors & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
