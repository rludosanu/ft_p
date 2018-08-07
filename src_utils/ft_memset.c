/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:45:45 by rludosan          #+#    #+#             */
/*   Updated: 2015/11/28 14:16:12 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*d;

	d = (char *)b;
	while (len > 0)
	{
		*d = (unsigned char)c;
		d++;
		len--;
	}
	return (b);
}
