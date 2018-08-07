/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_lls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int					client_lls(void)
{
	DIR				*d;
	struct dirent	*e;

	if ((d = opendir(".")))
	{
		ft_putstr("SUCCESS : Local directory retrieved\n");
		while ((e = readdir(d)) != NULL)
			if (ft_strcmp(e->d_name, ".") && ft_strcmp(e->d_name, ".."))
				if (ft_strlen(e->d_name) > 0)
					ft_printf("ss", e->d_name, "\n");
		closedir(d);
	}
	else
		return (client_error("ERROR : Unable to retrieve directory"));
	return (0);
}
