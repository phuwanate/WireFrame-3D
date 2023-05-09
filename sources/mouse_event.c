/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:28:02 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 10:45:38 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keyboard.h"

int	mouse_press(int event, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (event == MOUSE_SCROLL_UP || event == MOUSE_SCROLL_DOWN)
		scale(event, fdf);
	else if (event == MOUSE_LEFT)
		fdf->mouse->is_pressed = 1;
	return (0);
}

int	mouse_release(int event, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)event;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = 0;
	return (0);
}

int	mouse_update(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->old_x = fdf->mouse->x;
	fdf->mouse->old_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed != 0)
	{
		fdf->camera->beta += (x - fdf->mouse->old_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->old_y) * 0.002;
		draw_map(fdf->map, fdf);
	}
	return (0);
}
