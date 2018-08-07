/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/05/09 18:24:54 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				handle_child(int signum)
{
	int					status;

	if (signum == SIGCHLD)
		wait4(-1, &status, 0, 0);
}

static void				server_exec(char **cmd, t_server *srv, t_client *clt)
{
	char				**args;

	if (*cmd == NULL || (args = ft_strsplit(*cmd, ' ')) == NULL)
		send_msg(clt->sockfd, "ERROR : Server cannot parse command", 35);
	else if (!ft_strcmp(args[0], "get"))
		server_get(args[1], clt->sockfd);
	else if (!ft_strcmp(args[0], "put"))
		server_put(args[1], clt->sockfd);
	else if (!ft_strcmp(args[0], "pwd"))
		server_pwd(srv, clt);
	else if (!ft_strcmp(args[0], "ls"))
		server_ls(clt->sockfd);
	else if (!ft_strcmp(args[0], "cd"))
		server_cd(args[1], srv, &clt);
	ft_arrdel(&args);
	free(*cmd);
	*cmd = NULL;
}

static int				server_read(t_server *srv, t_client *clt)
{
	char				*cmd;
	char				buf[BUFSIZE];
	int					ret;
	int					ttret;

	ttret = 0;
	cmd = NULL;
	while ((ret = read(clt->sockfd, &buf, BUFSIZE - 1)) > 0)
	{
		signal(SIGCHLD, handle_child);
		buf[ret] = '\0';
		if (buf[ret - 1] == -1)
		{
			buf[ret - 1] = '\0';
			ft_strdcat(&cmd, (char *)&buf, ttret, ret - 1);
			server_exec(&cmd, srv, clt);
			ttret = 0;
		}
		else
		{
			ft_strdcat(&cmd, (char *)&buf, ttret, ret);
			ttret += ret;
		}
	}
	return (0);
}

static int				server_accept(t_server *srv)
{
	int					sockfd;
	struct sockaddr_in	sockin;
	unsigned int		sockln;

	sockfd = accept(srv->sockfd, (struct sockaddr *)&sockin, &sockln);
	if (sockfd == -1)
		return (server_error("INFO : Client connection failed"));
	return (sockfd);
}

int						server_handle(t_server *srv)
{
	t_client			*clt;
	int					sockclfd;
	pid_t				pid;

	while (1)
	{
		if ((sockclfd = server_accept(srv)) == -1)
			continue ;
		if ((pid = fork()) == -1)
			close(sockclfd);
		else if (pid == 0)
		{
			close(srv->sockfd);
			if ((clt = clt_create(sockclfd, srv->rootdir)) != NULL)
				server_read(srv, clt);
			clt_delete(&clt);
			exit(EXIT_SUCCESS);
		}
		else
			close(sockclfd);
	}
	return (0);
}
