/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloczero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:07 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/02 16:40:59 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*malloczero(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst)
		ft_bzero(dst, size);
	return (dst);
}
