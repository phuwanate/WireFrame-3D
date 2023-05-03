/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:46:33 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/03 00:46:38 by first            ###   ########.fr       */
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
int	ft_isvalid(char *s, int base);
int	read_map(int fd, t_coord_z **z_stack, t_map *map);
int	ft_atoi_base(char *s, int base);
void	stack_add(t_coord_z **z_stack, t_coord_z *new);

#endif
