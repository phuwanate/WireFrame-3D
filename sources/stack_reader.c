/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:36:53 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/03 08:36:54 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

void	stack_add(t_coord_z **z_stack, t_coord_z *new)
{
	if (z_stack)
	{
		if (new)
			new->next = *z_stack;
		*z_stack = new;
	}
}
