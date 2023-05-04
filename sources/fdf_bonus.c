/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/04 16:38:12 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int	main(int ac, char *av[])
{
	int				fd;
	t_map			*map;
	t_fdf			*fdf;
	t_coord_z		*z_stack;

	errno = 0;
	z_stack = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			force_quit(MAP_FDF);
		map = map_set();
		read_map(fd, &z_stack, map);
		fdf = fdf_set(map);
		stack_to_arr(&z_stack, map);
		fdf->camera = camera_set(fdf);
		draw_map(fdf->map, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		force_quit(PARAMETER);
	return (0);
}
