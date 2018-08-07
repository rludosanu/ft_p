/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int		read_file_content(int sockfd, int filefd, int filesize)
{
	char		buf[1024];
	int			ret;
	int			ttret;

	ttret = 0;
	while ((ret = read(sockfd, &buf, 1023)) > 0)
	{
		write(filefd, buf, ret);
		filesize -= ret;
		ttret += ret;
		if (filesize <= 0)
			break ;
	}
	return (ttret);
}

static int		create_file(int sockfd, char *file)
{
	int			fd;

	if (file == NULL || ft_strlen(file) == 0 || ft_strisempty(file))
	{
		send_msg(sockfd, "KO", 2);
		return (-1);
	}
	if (ft_file_exists(".", file))
	{
		if (unlink(file) == -1)
		{
			send_msg(sockfd, "KO", 2);
			return (-1);
		}
	}
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, \
		S_IRWXU)) == -1)
	{
		send_msg(sockfd, "KO", 2);
		return (-1);
	}
	send_msg(sockfd, "OK", 2);
	return (fd);
}

static char		*get_file_name(int sockfd, char *file)
{
	char		*name;
	char		**tmp;

	name = NULL;
	if (!(tmp = ft_strsplit(file, '/')))
		name = ft_strdup("tmp");
	else
	{
		name = ft_strdup(tmp[ft_arrlen(tmp) - 1]);
		ft_arrdel(&tmp);
	}
	if (name == NULL)
		send_msg(sockfd, "KO", 2);
	return (name);
}

static int		read_file_size(int sockfd)
{
	char		*buf;
	int			size;

	buf = read_msg(sockfd);
	size = ft_atoi(buf);
	if (buf != NULL)
		free(buf);
	return (size);
}

int				server_put(char *file, int sockfd)
{
	int			filesize;
	char		*filename;
	int			filefd;

	send_msg(sockfd, "OK", 2);
	if ((filesize = read_file_size(sockfd)) > 0)
	{
		if ((filename = get_file_name(sockfd, file)) != NULL)
		{
			if ((filefd = create_file(sockfd, filename)) != -1)
			{
				if (read_file_content(sockfd, filefd, filesize) == filesize)
					send_msg(sockfd, "OK", 2);
				else
					send_msg(sockfd, "KO", 2);
				close(filefd);
			}
			free(filename);
		}
	}
	else
		send_msg(sockfd, "KO", 2);
	return (0);
}
