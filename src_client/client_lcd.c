/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_lcd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		client_lcd(char *path)
{
	if (path == NULL || ft_strlen(path) == 0 || ft_strisempty(path))
		return (client_error("USAGE: lcd <path>"));
	else if (chdir(path) == -1)
		return (client_error("ERROR: unable to change directory"));
	client_lpwd();
	return (0);
}
