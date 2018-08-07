/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int				client_cd(char *cmd, char *path, int sockfd)
{
	char		*msg;

	if (path == NULL || ft_strlen(path) == 0 || ft_strisempty(path))
		return (client_error("USAGE: lcd / cd <path>"));
	send_msg(sockfd, cmd, ft_strlen(cmd));
	msg = read_msg(sockfd);
	ft_printf("ss", msg, "\n");
	if (msg != NULL)
		free(msg);
	return (0);
}
