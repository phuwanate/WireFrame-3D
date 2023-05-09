/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:43 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 10:42:58 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "fdf.h"

void	scale(int event, t_fdf *fdf)
{
	if (event == KEY_MAIN_PLUS || event == MOUSE_SCROLL_UP)
		fdf->camera->scale++;
	else if (event == KEY_MAIN_MINUS || event == MOUSE_SCROLL_DOWN)
		fdf->camera->scale--;
	if (fdf->camera->scale < 1)
		fdf->camera->scale = 1;
	draw_map(fdf->map, fdf);
}

void	translate(int event, t_fdf *fdf)
{
	if (event == ARROW_LEFT)
		fdf->camera->x_offset -= 12;
	else if (event == ARROW_RIGHT)
		fdf->camera->x_offset += 12;
	else if (event == ARROW_DOWN)
		fdf->camera->y_offset += 12;
	else if (event == ARROW_UP)
		fdf->camera->y_offset -= 12;
	draw_map(fdf->map, fdf);
}

void	rotate(int event, t_fdf *fdf)
{
	if (event == KEY_MAIN_1)
		fdf->camera->alpha += 0.07;
	else if (event == KEY_MAIN_2)
		fdf->camera->alpha -= 0.07;
	else if (event == KEY_MAIN_3)
		fdf->camera->beta += 0.07;
	else if (event == KEY_MAIN_4)
		fdf->camera->beta -= 0.07;
	else if (event == KEY_MAIN_5)
		fdf->camera->gamma += 0.07;
	else if (event == KEY_MAIN_6)
		fdf->camera->gamma -= 0.07;
	draw_map(fdf->map, fdf);
}

void	altitude(int event, t_fdf *fdf)
{
	if (event == KEY_LESS_THAN)
		fdf->camera->z_height -= 0.1;
	else if (event == KEY_MORE_THAN)
		fdf->camera->z_height += 0.1;
	if (fdf->camera->z_height < 0.1)
		fdf->camera->z_height = 0.1;
	else if (fdf->camera->z_height > 10)
		fdf->camera->z_height = 10;
	draw_map(fdf->map, fdf);
}

void	projection_type(int event, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (event == KEY_MAIN_I)
		fdf->camera->proj_type = ISO;
	else if (event == KEY_MAIN_P)
		fdf->camera->proj_type = PARA;
	draw_map(fdf->map, fdf);
}
