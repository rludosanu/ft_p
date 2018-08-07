/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int		count_path(char **pdirs, int ndirs)
{
	int			n;

	n = 0;
	while (n < ft_arrlen(pdirs))
	{
		if (ndirs < 0)
			break ;
		else if (ft_strcmp(pdirs[n], "..") == 0)
			ndirs--;
		else if (ft_strcmp(pdirs[n], ".") != 0)
			ndirs++;
		n++;
	}
	return (ndirs);
}

static int		check_path(char *path, char *rootdir, char *currdir)
{
	char		*wd;
	char		**pdirs;
	char		**cdirs;
	int			ndirs;

	if (!path || !rootdir || !currdir)
		return (-1);
	wd = ft_putstrcmp(rootdir, currdir);
	pdirs = ft_strsplit(path, '/');
	cdirs = ft_strsplit(wd, '/');
	ndirs = (*wd == '\0') ? 0 : ft_arrlen(cdirs);
	ndirs = count_path(pdirs, ndirs);
	ft_arrdel(&pdirs);
	ft_arrdel(&cdirs);
	return ((ndirs < 0) ? -1 : 0);
}

static int		error_path(int sockfd)
{
	send_msg(sockfd, "ERROR : Unable to change directory", 34);
	return (-1);
}

static int		change_path(char *path, t_server *srv, t_client **clt)
{
	if (path == NULL)
		return (error_path((*clt)->sockfd));
	else if (*path != '\0' && chdir(path) == -1)
		return (error_path((*clt)->sockfd));
	if ((*clt)->currdir)
		free((*clt)->currdir);
	(*clt)->currdir = ft_getcwd();
	server_pwd(srv, *clt);
	return (0);
}

int				server_cd(char *path, t_server *srv, t_client **clt)
{
	if (path == NULL || ft_strlen(path) == 0 || ft_strisempty(path))
		return (error_path((*clt)->sockfd));
	if (*path == '/')
	{
		chdir(srv->rootdir);
		while (*path == '/')
			path++;
	}
	if (*path == '\0')
		return (change_path(path, srv, clt));
	else if (path && check_path(path, srv->rootdir, (*clt)->currdir) == -1)
		return (error_path((*clt)->sockfd));
	return (change_path(path, srv, clt));
}
