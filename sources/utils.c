#include "../libft/libft.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void	force_quit(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}
