/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:05 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 10:44:31 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "keyboard.h"
#include <stdlib.h>

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_MAIN_MINUS || key == KEY_MAIN_PLUS)
		scale(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_DOWN || key == ARROW_UP)
		translate(key, fdf);
	else if (key == KEY_MAIN_1 || key == KEY_MAIN_2
		|| key == KEY_MAIN_3 || key == KEY_MAIN_4
		|| key == KEY_MAIN_5 || key == KEY_MAIN_6)
		rotate(key, fdf);
	else if (key == KEY_MORE_THAN || key == KEY_LESS_THAN)
		altitude(key, fdf);
	else if (key == KEY_MAIN_I || key == KEY_MAIN_P)
		projection_type(key, fdf);
	return (0);
}
