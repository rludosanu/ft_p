/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int					ft_file_exists(char *dir, char *file)
{
	DIR				*d;
	struct dirent	*e;

	d = (!dir) ? opendir(".") : opendir(dir);
	if (d == NULL)
		return (-1);
	while ((e = readdir(d)) != NULL)
	{
		if (ft_strcmp(e->d_name, file) == 0)
		{
			closedir(d);
			return (1);
		}
	}
	closedir(d);
	return (0);
}
