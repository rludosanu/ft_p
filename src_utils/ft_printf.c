/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:32:07 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/06 15:53:07 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void			ft_printf(char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	while (fmt && *fmt)
	{
		if (*fmt == 'c')
			ft_putchar(va_arg(ap, int));
		else if (*fmt == 's')
			ft_putstr(va_arg(ap, char *));
		else if (*fmt == 'd')
			ft_putnbr(va_arg(ap, int));
		else if (*fmt == 'x')
			ft_puthex(va_arg(ap, unsigned int));
		fmt++;
	}
}
