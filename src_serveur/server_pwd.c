/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int				server_pwd(t_server *srv, t_client *clt)
{
	char		*cwd;
	char		eot;

	eot = -1;
	if (srv->rootdir != NULL && clt->currdir != NULL)
	{
		write(clt->sockfd, "SUCCESS : Remote directory is ", 30);
		cwd = ft_putstrcmp(srv->rootdir, clt->currdir);
		if (cwd && *cwd == '\0')
			write(clt->sockfd, "/", 1);
		else
			write(clt->sockfd, cwd, ft_strlen(cwd));
		cwd = NULL;
	}
	write(clt->sockfd, &eot, 1);
	return (0);
}
