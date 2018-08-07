/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:32:07 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/06 15:53:07 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void				ft_puthex(unsigned int n)
{
	const char		base[] = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16);
	ft_putchar(base[n % 16]);
}