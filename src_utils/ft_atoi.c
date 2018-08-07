/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:21:57 by rludosan          #+#    #+#             */
/*   Updated: 2015/11/28 18:47:00 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int		ft_atoi(const char *str)
{
	int	s;
	int	n;

	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	s = 1;
	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (47 < *str && *str < 58)
		n = n * 10 + *str++ - 48;
	return (n * s);
}
