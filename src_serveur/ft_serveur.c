/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/05/24 14:03:19 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				server_delete(t_server **srv)
{
	if (!srv || !(*srv))
		return ;
	if ((*srv)->rootdir != NULL)
		free((*srv)->rootdir);
	if ((*srv)->sockfd != -1)
		close((*srv)->sockfd);
	free(*srv);
	*srv = NULL;
}

static int				server_socket(int port, int backlog)
{
	int					sockfd;
	struct sockaddr_in	sockin;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (server_error("ERROR : Cannot create socket"));
	sockin.sin_family = AF_INET;
	sockin.sin_port = htons(port);
	sockin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&sockin, sizeof(sockin)) < 0)
	{
		close(sockfd);
		return (server_error("ERROR : Cannot bind socket"));
	}
	if (listen(sockfd, backlog) < 0)
	{
		close(sockfd);
		return (server_error("ERROR : Cannot listen on socket"));
	}
	return (sockfd);
}

static t_server			*server_create(int port, int backlog)
{
	t_server			*srv;

	srv = NULL;
	if ((srv = (t_server *)malloc(sizeof(t_server))) == NULL)
		return (NULL);
	srv->sockfd = server_socket(port, backlog);
	srv->rootdir = ft_getcwd();
	if (srv->sockfd < 1 || srv->rootdir == NULL)
		server_delete(&srv);
	return (srv);
}

int						main(int ac, char **av)
{
	t_server			*srv;

	srv = NULL;
	if (ac != 2)
		return (server_error("Usage : ./serveur <port>"));
	if ((srv = server_create(ft_atoi(av[1]), 42)) != NULL)
	{
		server_handle(srv);
		server_delete(&srv);
	}
	return (0);
}
