#ifndef FDF_H
#define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define INSTRUCTION 200;



typedef struct s_map
{
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	int		ratio;
	int		*coord;
	int		*colors;

}			t_map;

void	force_quit(char *s);

#endif
