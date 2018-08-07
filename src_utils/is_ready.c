/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ready.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int			is_ready(int sockfd)
{
	int		ret;
	char	*buf;

	ret = 0;
	buf = read_msg(sockfd);
	if (buf != NULL)
	{
		if (!ft_strcmp(buf, "OK"))
			ret = 1;
		free(buf);
	}
	return (ret);
}
