/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 16:04:09 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static void		ft_memzero(void *ptr, size_t size)
{
	char		*tmp;
	size_t		cmp;

	tmp = (char *)ptr;
	cmp = 0;
	while (cmp < size)
		tmp[cmp++] = '\0';
}

static void		*ft_memalloc(size_t size)
{
	void		*ptr;

	if (!(ptr = (void *)malloc(size)))
		return (NULL);
	ft_memzero(ptr, size);
	return (ptr);
}

char			*ft_strdcat(char **s1, char *s2, size_t l1, size_t l2)
{
	char		*new;
	char		*s;
	size_t		x;
	size_t		y;

	s = *s1;
	if (!(new = ft_memalloc(l1 + l2 + 1)))
		return (NULL);
	y = 0;
	x = 0;
	while (x < l1)
		new[y++] = s[x++];
	x = 0;
	while (x < l2)
		new[y++] = s2[x++];
	free(*s1);
	*s1 = new;
	return (new);
}
