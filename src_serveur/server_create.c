/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/05/09 14:57:04 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int						server_create(int port, int backlog)
{
	int					sockfd;
	struct sockaddr_in	sockin;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		return (server_error("ERROR: cannot create socket"));
	sockin.sin_family = AF_INET;
	sockin.sin_port = htons(port);
	sockin.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&sockin, sizeof(sockin)) != 0)
	{
		close(sockfd);
		return (server_error("ERROR: cannot bind socket"));
	}
	if (listen(sockfd, backlog) != 0)
	{
		close(sockfd);
		return (server_error("ERROR: cannot listen on socket"));
	}
	return (sockfd);
}
