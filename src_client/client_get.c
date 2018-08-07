/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_get.c                                       :+:      :+:    :+:   */
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
	int			size;

	size = filesize;
	ttret = 0;
	while ((ret = read(sockfd, &buf, 1023)) > 0)
	{
		write(filefd, buf, ret);
		filesize -= ret;
		ttret += ret;
		if (filesize <= 0)
			break ;
	}
	if (ttret == size)
		return (0);
	return (-1);
}

static int		create_file(int sockfd, char *file)
{
	int			fd;

	if (file == NULL || ft_strlen(file) == 0 || ft_strisempty(file))
		return (-1);
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

static int		read_file_size(int sockfd, char *cmd)
{
	char		*buf;
	int			size;

	send_msg(sockfd, cmd, ft_strlen(cmd));
	buf = read_msg(sockfd);
	size = ft_atoi(buf);
	if (buf != NULL)
		free(buf);
	if (size == 0)
		send_msg(sockfd, "KO", 2);
	return (size);
}

int				client_get(char *cmd, char *file, int sockfd)
{
	int			ret;
	int			filesize;
	char		*filename;
	int			filefd;

	ret = -1;
	if (file == NULL || ft_strlen(file) == 0 || ft_strisempty(file))
		return (client_error("USAGE: get <path>"));
	if ((filesize = read_file_size(sockfd, cmd)) > 0)
	{
		if ((filename = get_file_name(sockfd, file)) != NULL)
		{
			if ((filefd = create_file(sockfd, filename)) != -1)
			{
				ret = read_file_content(sockfd, filefd, filesize);
				close(filefd);
			}
			free(filename);
		}
	}
	ft_putstr((ret == 0) ? "SUCCESS : File downloaded\n" \
		: "ERROR : File not downloaded\n");
	return (ret);
}
