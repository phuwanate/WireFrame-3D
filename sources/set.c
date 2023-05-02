/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:57:36 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/02 16:43:00 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../includes/error.h"

t_map	*map_set(void)
{
	t_map	*map;

	map = (t_map *)malloczero(sizeof(t_map));
	if (!(map))
		force_quit(MAP_SET);
	map->width = 0;
	map->height = 0;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	return (map);
}

