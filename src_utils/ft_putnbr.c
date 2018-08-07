/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:32:07 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/06 15:53:07 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void				ft_putnbr(int n)
{
	unsigned int	x;

	if (n < 0)
	{
		ft_putchar('-');
		x = (unsigned int)n * -1;
	}
	else
		x = (unsigned int)n;
	if (x >= 10)
		ft_putnbr(x / 10);
	ft_putchar((x % 10) + '0');
}
