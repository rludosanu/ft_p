/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int					server_ls(int sockfd)
{
	DIR				*d;
	struct dirent	*e;
	char			eot;

	eot = -1;
	if ((d = opendir(".")))
	{
		write(sockfd, "SUCCESS : Remote directory retrieved\n", 37);
		while ((e = readdir(d)) != NULL)
		{
			if (ft_strcmp(e->d_name, ".") && ft_strcmp(e->d_name, ".."))
			{
				if (ft_strlen(e->d_name) > 0)
				{
					write(sockfd, e->d_name, ft_strlen(e->d_name));
					write(sockfd, "\n", 1);
				}
			}
		}
		closedir(d);
	}
	else
		write(sockfd, "ERROR : Unable to read directory", 32);
	write(sockfd, &eot, 1);
	return (0);
}
