/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:59:41 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/02 18:30:30 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

static int	ft_isvalid(char *s, int base)
{
	size_t	i;
	size_t	digits;

	i = 0;
	digits = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v')
		|| (s[i] == '\f') || (s[i] == '\r'))
		i++;
	if (base == 16)
		i += 2;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	// while(ft_isvalid(str[i], base))
	// {
		
	// }
}