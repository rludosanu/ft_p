/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:08:18 by rludosan          #+#    #+#             */
/*   Updated: 2015/11/27 11:33:14 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	char	*ptd;

	d = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!d)
		return (NULL);
	ptd = d;
	while (*s1)
		*d++ = *s1++;
	*d = '\0';
	return (ptd);
}
