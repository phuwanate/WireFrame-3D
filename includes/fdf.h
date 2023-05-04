/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:46:33 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/04 19:57:48 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define MENU 200

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef enum s_projection
{
	iso,
	parrallel
}						t_projection;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					colors;
}						t_point;

typedef struct s_camera
{
	int					scale;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_height;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					old_x;
	int					old_y;
}						t_mouse;
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
typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_map				*map;
	t_mouse				*mouse;
	t_camera			*camera;
}						t_fdf;

typedef struct s_coord_z
{
	int					z;
	int					color;
	struct s_coord_z	*next;
}						t_coord_z;	

void		force_quit(char *s);
t_map		*map_set(void);
int			ft_isvalid(char *s, int base);
int			read_map(int fd, t_coord_z **z_stack, t_map *map);
int			ft_atoi_base(char *s, int base);
void		stack_add(t_coord_z **z_stack, t_coord_z *new);
void		stack_to_arr(t_coord_z **z_stack, t_map *map);
t_fdf		*fdf_set(t_map *map);
t_coord_z	*pick_stack(t_coord_z **z_stack);
t_camera	*camera_set(t_fdf *fdf);
void		draw_map(t_map *map, t_fdf *fdf);

#endif
