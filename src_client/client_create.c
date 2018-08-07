/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 16:04:09 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int						client_create(char *machine, int port)
{
	int					sockfd;
	struct sockaddr_in	sockin;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		return (client_error("ERROR: cannot create socket"));
	sockin.sin_family = AF_INET;
	sockin.sin_port = htons(port);
	sockin.sin_addr.s_addr = inet_addr(machine);
	if (connect(sockfd, (struct sockaddr *)&sockin, sizeof(sockin)) == -1)
	{
		close(sockfd);
		return (client_error("ERROR: cannot connect socket"));
	}
	return (sockfd);
}
