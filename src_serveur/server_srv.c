/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static char		*get_rootdir(char *basedir)
{
	char		*tmp;
	char		*dir;

	if (basedir == NULL)
		return (NULL);
	dir = NULL;
	if ((tmp = ft_strcat(basedir, "/")))
	{
		dir = ft_strcat(tmp, "global");
		if (chdir("./global") == -1)
		{
			free(dir);
			dir = NULL;
		}
		free(tmp);
	}
	return (dir);
}

t_server		*srv_create(int port, int backlog)
{
	t_server	*srv;

	if (chdir("./root") == -1)
	{
		ft_putstr("ERROR: Server root directory is unreachable\n");
		return (NULL);
	}
	if (!(srv = (t_server *)malloc(sizeof(t_server))))
	{
		ft_putstr("ERROR: Unable to create server\n");
		return (NULL);
	}
	if ((srv->sockfd = server_create(port, backlog)) != -1)
	{
		srv->port = port;
		srv->backlog = backlog;
		srv->basedir = ft_getcwd();
		srv->rootdir = get_rootdir(srv->basedir);
		if (srv->basedir && srv->rootdir)
			return (srv);
	}
	ft_putstr("ERROR: Unable to establish internal file system\n");
	srv_delete(&srv);
	return (NULL);
}

void			srv_delete(t_server **srv)
{
	if (!(*srv))
		return ;
	if ((*srv)->rootdir != NULL)
		free((*srv)->rootdir);
	if ((*srv)->basedir != NULL)
		free((*srv)->basedir);
	(*srv)->rootdir = NULL;
	(*srv)->basedir = NULL;
	close((*srv)->sockfd);
	free(*srv);
	*srv = NULL;
}
