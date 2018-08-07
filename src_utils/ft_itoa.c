/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:18:17 by rludosan          #+#    #+#             */
/*   Updated: 2015/11/28 16:08:49 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static int			ft_size_itoa(int n)
{
	int				size;
	unsigned int	x;

	size = 0;
	if (n < 0)
	{
		size++;
		x = (unsigned int)n * -1;
	}
	else
		x = (unsigned int)n;
	while (x != 0)
	{
		x = x / 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	x;

	len = ft_size_itoa(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		str[0] = '-';
		x = (unsigned int)n * -1;
	}
	else
		x = (unsigned int)n;
	str[len] = '\0';
	while (x != 0)
	{
		len--;
		str[len] = (x % 10) + '0';
		x = x / 10;
	}
	return (str);
}
