#include "../includes/fdf.h"
#include <stdlib.h>

void	stack_add(t_coord_z **z_stack, t_coord_z *new)
{
	if(z_stack)
	{
		if(new)
			new->next = *z_stack;
		*z_stack = new;
	}
}
