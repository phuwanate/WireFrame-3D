/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:59:41 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/09 10:42:47 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int	ft_isbase(char s, int base)
{
	char	*base_num;
	int		i;

	base_num = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (base_num[i] == ft_toupper(s) || base_num[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_prefix(char *s, int base)
{
	int	i;

	i = 0;
	if (s[i] == '0')
		i++;
	if ((base == 16) && (s[i] == 'X' || s[i] == 'x'))
		return (1);
	return (0);
}

int	ft_isvalid(char *s, int base)
{
	size_t	i;
	size_t	digit;

	i = 0;
	digit = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v')
		|| (s[i] == '\f') || (s[i] == '\r'))
		i++;
	if (base != 10 && !ft_prefix(&s[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
		i++;
	while (ft_isbase(s[i], base) >= 0)
	{
		i++;
		digit++;
	}
	if ((s[i] == '\0') || digit)
		return (1);
	else
		return (0);
}

int	ft_atoi_base(char *s, int base)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v')
		|| (s[i] == '\f') || (s[i] == '\r'))
		i++;
	if (ft_prefix(&s[i], base) == 0)
		return (0);
	i += 2;
	while (ft_isbase(s[i], base) >= 0)
	{
		result = result * base + ft_isbase(s[i], base);
		i++;
	}
	return ((int)(result));
}
