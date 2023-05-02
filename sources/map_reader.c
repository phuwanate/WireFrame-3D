/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:29:14 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/02 18:30:38 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line/get_next_line.h"
#include "../includes/fdf.h"
#include "../includes/error.h"
#include <stdlib.h>


// static t_coord_z *new_stack(char *s)
// {
// 	t_coord_z	*new;
// 	char		**
// }


static void	line_tostack(char **line_split, t_coord_z z_stack, t_map *map)
{
	int width;

	width = 0;
	while(*line_split)
	{
		stack_addback(z_stack, new_stack(*(line_split)));
		line_split++;
		width++;
	}
}


int	read_map(int fd, t_coord_z **z_stack, t_map *map)
{
	char	*line;
	char	**line_split;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_split = ft_split(line, ' ');
		if(!line_split)
			force_quit(MAP_READ);
		line_tostack(line_split, z_stack, map);
	}
	if (!(*z_stack))
		force_quit(MAP_FDF);
}
