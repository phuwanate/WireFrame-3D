/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:45 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/10 16:30:56 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

double	percent(int start, int end, int curr)
{
	double	cur_point;
	double	distance;

	cur_point = curr - start;
	distance = end - start;
	if (distance == 0)
		return (0);
	else
		return (cur_point / distance);
}

void	force_quit(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

t_point	get_point(int x, int y, t_map *map)
{
	t_point		point;
	int			index;

	index = y * map->width + x;
	point.x = x;
	point.y = y;
	point.z = map->coord[index];
	if (map->colors[index] == -1)
		point.colors = default_color(point.z, map);
	else
		point.colors = map->colors[index];
	return (point);
}

int	absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_ismin(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
}

//get_color.c: default_color()
//libft.h: ft_putendl_fd()
//stdio.h: perror(), exit()