/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_lpwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int			client_lpwd(void)
{
	char	*buf;
	size_t	size;

	size = 512;
	if (!(buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (client_error("ERROR : Unable to retreive path"));
	if (!(getcwd(buf, size)))
		return (client_error("ERROR : Unable to retreive path"));
	buf[size] = '\0';
	ft_printf("sss", "SUCCESS : Local directory is ", buf, "\n");
	if (buf != NULL)
		free(buf);
	return (0);
}
