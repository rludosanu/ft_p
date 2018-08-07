/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/05/09 20:02:26 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int				client_connect(char *machine, int port)
{
	int					sockfd;
	struct sockaddr_in	sockin;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (client_error("ERROR : Cannot create socket"));
	sockin.sin_family = AF_INET;
	sockin.sin_port = htons(port);
	sockin.sin_addr.s_addr = inet_addr(machine);
	if (connect(sockfd, (struct sockaddr *)&sockin, sizeof(sockin)) < 0)
	{
		close(sockfd);
		return (client_error("ERROR : Cannot connect socket"));
	}
	return (sockfd);
}

int						main(int ac, char **av)
{
	int					sockfd;

	if (ac != 3)
		return (client_error("USAGE : ./client <machine> <port>"));
	if ((sockfd = client_connect(av[1], ft_atoi(av[2]))) < 0)
		return (-1);
	client_handle(sockfd);
	close(sockfd);
	ft_putstr("SUCCESS : Closing client\n");
	return (0);
}
