/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:01:52 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/10 16:01:48 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "error.h"
#include <stdlib.h>

static void	check_malloc(int *arr)
{
	if (!arr)
		force_quit(CONV_ARR);
}

static int	update_zmax(int top, int max)
{
	if (top > max)
		return (top);
	return (max);
}

static int	update_zmin(int top, int min)
{
	if (top < min)
		return (top);
	return (min);
}

void	stack_to_arr(t_coord_z **z_stack, t_map *map)
{
	t_coord_z	*top;
	ssize_t		i;
	size_t		size;

	size = map->width * map->height * sizeof(int);
	map->coord = (int *)malloczero(size);
	check_malloc(map->coord);
	map->colors = (int *)malloczero(size);
	check_malloc(map->colors);
	i = map->width * map->height - 1;
	while (i >= 0)
	{
		top = pick_stack(z_stack);
		if (top)
		{
			map->coord[i] = top->z;
			map->colors[i] = top->color;
			map->z_max = update_zmax(top->z, map->z_max);
			map->z_min = update_zmin(top->z, map->z_min);
		}
		else
			break ;
		i--;
		free(top);
	}
}

//libft.h : malloczero()
//stack_reader.c: pick_stack()
