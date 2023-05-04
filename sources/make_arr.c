/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:01:52 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/04 16:39:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "../mlx/mlx.h"
#include "../includes/error.h"
#include <stdlib.h>

static void	check_malloc(void *arr)
{
	if (!arr)
		force_quit(CONV_ARR);
}

void	stack_to_arr(t_coord_z **z_stack, t_map *map)
{
	t_coord_z	*top;
	size_t		i;
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
			if (top->z > map->z_max)
				map->z_max = top->z;
			if (top->z < map->z_min)
				map->z_min = top->z;
		}
		i--;
		free(top);
	}
}
