/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 16:04:09 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char		*read_msg(int fd)
{
	char	*tmp;
	char	buf[1024];
	int		ret;
	int		ttret;

	ret = 0;
	ttret = 0;
	tmp = NULL;
	while ((ret = read(fd, &buf, 1023)) > 0)
	{
		buf[ret] = '\0';
		if (buf[ret - 1] == -1)
		{
			buf[ret - 1] = '\0';
			ft_strdcat(&tmp, (char *)&buf, ttret, ret - 1);
			break ;
		}
		else
		{
			ft_strdcat(&tmp, (char *)&buf, ttret, ret);
			ttret += ret;
		}
	}
	return (tmp);
}
