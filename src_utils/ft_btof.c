/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int			ft_btof(char *file, char *buf, size_t len)
{
	int		fd;

	if (!file || !buf)
		return (-1);
	if (ft_file_exists(".", file))
	{
		if (unlink(file) == -1)
		{
			return (-1);
		}
	}
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) == -1)
	{
		return (-1);
	}
	write(fd, buf, len);
	close(fd);
	return (0);
}
