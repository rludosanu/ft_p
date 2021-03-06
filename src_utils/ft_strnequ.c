/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int			ft_strnequ(char *s1, char *s2, int len)
{
	char	*t1;
	char	*t2;

	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	t1 = s1;
	t2 = s2;
	while (*t1 != '\0' && *t2 != '\0' && *t1 == *t2 && len > 0)
	{
		t1++;
		t2++;
		len--;
	}
	if (len == 0)
		return (1);
	return (0);
}
