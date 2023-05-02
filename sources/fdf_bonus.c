/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/02 15:09:54 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <errno.h>

int	main(int ac, char *av[])
{
	int				fd;
	t_map			*map;
	t_coord_z		*z_stack;	

	if (ac == 2)
	{
		errno = 0;
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			force_quit(MAP_FDF);
		map = map_set();
		if (read_map(fd, &z_stack, map) == -1)
			force_quit(MAP_READ);
	}
	force_quit(PARAMETER);
	return (0);
}
