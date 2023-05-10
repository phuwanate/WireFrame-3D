/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:46:33 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 13:07:23 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define WIDTH	1920
# define HEIGHT 1080
# define MENU 	290

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef enum s_projection
{
	ISO,
	PARA
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
	t_projection		proj_type;
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
int			absolute(int nb);
int			ft_ismin(int x, int y);
void		scale(int event, t_fdf *fdf);
void		translate(int event, t_fdf *fdf);
void		rotate(int event, t_fdf *fdf);
void		altitude(int event, t_fdf *fdf);
void		projection_type(int event, t_fdf *fdf);
int			key_press(int key, void *param);
int			mouse_press(int event, int x, int y, void *param);
int			mouse_release(int event, int x, int y, void *param);
int			mouse_update(int x, int y, void *param);
int			close_win(void *param);
int			get_color(t_point cur, t_point start,
				t_point end, t_point distance);
t_point		plot_xyz(t_point point, t_fdf *fdf);
t_point		get_point(int x, int y, t_map *map);
void		put_menu(t_fdf *fdf);
int			default_color(int z, t_map *map);
double		percent(int start, int end, int curr);
void		control(t_fdf *fdf);

#endif
