#include "../mlx/mlx.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <errno.h>

int main(int ac, char *av[])
{
	int		fd;
	if(ac == 2)
	{
		errno = 0;
		if(!(fd = open(av[1], O_RDONLY) >= 0))
			force_quit("MAP ERROR");
		//map = map_start();
	}
}	
