/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_login.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int					client_login(char *cmd, char **args, int sockfd)
{
	char			*msg;

	if (!args || ft_arrlen(args) != 2)
		return (client_error("USAGE: login <username> <password>"));
	send_msg(sockfd, cmd, ft_strlen(cmd));
	msg = read_msg(sockfd);
	ft_printf("ss", msg, "\n");
	if (msg != NULL)
		free(msg);
	return (0);
}
