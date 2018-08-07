/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_login.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int			change_usrdir(char *usr, t_server **srv, t_client **clt)
{
	char			*tmp;
	char			*sdir;
	char			*cdir;

	sdir = NULL;
	cdir = NULL;
	if ((tmp = ft_strcat((*srv)->basedir, "/")))
	{
		sdir = ft_strcat(tmp, usr);
		cdir = ft_strdup(sdir);
		free(tmp);
	}
	if (sdir && cdir)
	{
		if (chdir(cdir) != -1)
		{
			ft_strreplace(&(*srv)->rootdir, sdir);
			ft_strreplace(&(*clt)->currdir, cdir);
			return (0);
		}
		free(sdir);
		free(cdir);
	}
	return (-1);
}

static int			fetch_ids(char *buf, char *usr, char *pwd)
{
	char			**lines;
	char			**ids;
	int				ret;
	int				cmp;

	if (!(lines = ft_strsplit(buf, ';')))
		return (-1);
	ret = -1;
	cmp = 0;
	while (cmp < ft_arrlen(lines))
	{
		if ((ids = ft_strsplit(lines[cmp], ':')))
		{
			if (!ft_strcmp(ids[0], usr) && !ft_strcmp(ids[1], pwd))
			{
				ret = 0;
				ft_arrdel(&ids);
				break ;
			}
			ft_arrdel(&ids);
		}
		cmp++;
	}
	ft_arrdel(&lines);
	return (ret);
}

static int			read_ids(char *usr, char *pwd, \
	t_server **srv, t_client **clt)
{
	int				ret;
	int				fd;
	struct stat		st;
	char			*buf;

	ret = -1;
	if ((fd = open("../../ids", O_RDONLY)) != -1)
	{
		if ((fstat(fd, &st)) != -1 && S_ISREG(st.st_mode))
		{
			if ((buf = mmap(0, st.st_size, \
				PROT_READ, MAP_PRIVATE, fd, 0)) != MAP_FAILED)
			{
				if (fetch_ids(buf, usr, pwd) != -1)
					ret = change_usrdir(usr, srv, clt);
				munmap(buf, st.st_size);
			}
		}
		close(fd);
	}
	return (ret);
}

int					server_login(char *usr, char *pwd, \
	t_server **srv, t_client **clt)
{
	int				ret;

	ret = read_ids(usr, pwd, srv, clt);
	if (ret == -1)
		send_msg((*clt)->sockfd, "ERROR: Invalid username or password", 35);
	else if (ret == -2)
		send_msg((*clt)->sockfd, "ERROR: Cannot access user directory", 35);
	else
		send_msg((*clt)->sockfd, "SUCCESS: User logged in", 23);
	return (0);
}
