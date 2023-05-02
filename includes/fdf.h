/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:46:33 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/02 15:09:17 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define INSTRUCTION 200

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef struct s_map
{
	int					width;
	int					height;
	int					z_min;
	int					z_max;
	int					ratio;
	int					*coord;
	int					*colors;

}						t_map;

typedef struct s_coord_z
{
	int					z;
	int					color;
	struct s_coord_z	*next;
}						t_coord_z;	


void	force_quit(char *s);
t_map	*map_set(void);

#endif
