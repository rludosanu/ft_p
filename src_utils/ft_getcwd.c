/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char			*ft_getcwd(void)
{
	char		*dir;
	size_t		size;

	size = 512;
	if (!(dir = ft_strnew(size)))
		return (NULL);
	if (!(getcwd(dir, size)))
	{
		free(dir);
		return (NULL);
	}
	return (dir);
}
