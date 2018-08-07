/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:55:36 by rludosan          #+#    #+#             */
/*   Updated: 2016/07/18 18:10:13 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void		ft_arrdel(char ***a)
{
	int		x;

	x = 0;
	if (*a != NULL && **a != NULL)
	{
		while ((*a)[x] != NULL)
		{
			free((*a)[x]);
			x++;
		}
		free(*a);
		*a = NULL;
	}
}