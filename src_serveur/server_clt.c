/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_clt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_client		*clt_create(int sockfd, char *rootdir)
{
	t_client	*clt;

	if (!(clt = (t_client *)malloc(sizeof(t_client))))
		return (NULL);
	clt->sockfd = sockfd;
	clt->currdir = ft_strdup(rootdir);
	return (clt);
}

void			clt_delete(t_client **clt)
{
	if (!(*clt))
		return ;
	if ((*clt)->currdir != NULL)
	{
		free((*clt)->currdir);
		(*clt)->currdir = NULL;
	}
	close((*clt)->sockfd);
	free(*clt);
	*clt = NULL;
}
