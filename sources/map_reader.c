/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:29:14 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/03 00:56:05 by first            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "../includes/error.h"
#include <stdlib.h>


static void	free_split(char **arr)
{
	size_t i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static t_coord_z *new_stack(char *s)
{
 	t_coord_z	*new;
 	char		**z_val;

	new = (t_coord_z *)malloczero(sizeof(t_coord_z));
	z_val = ft_split(s, ',');
	if ((!new) || (!z_val))
		force_quit(MAP_READ);
	if (!(ft_isvalid(z_val[0], 10)))
		force_quit(MAP_READ);
	if (z_val[1] && ft_isvalid(z_val[10], 16))
		force_quit(MAP_READ);
	new->z = ft_atoi(z_val[0]);
	if (z_val[1] != NULL )
		new->color = ft_atoi_base(z_val[1], 16);
	else
		new->color = -1;
	new->next = NULL;
	free_split(z_val);
	return (new);
}


static void	line_tostack(char **line_split, t_coord_z **z_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*line_split)
	{
		stack_add(z_stack, new_stack(*(line_split)));
		line_split++;
		width++;
	}
	if(map->height == 0)
		map->width = width;
	else if(map->width != width)
		force_quit(MAP_FDF);
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
	return(0);
}
