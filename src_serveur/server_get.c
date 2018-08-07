/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void			server_get_end(int sockfd, int ret)
{
	if (ret == -1)
	{
		send_msg(sockfd, "0", 1);
		is_ready(sockfd);
	}
}

static int			send_file_data(int sockfd, char *filebuf, int filesize)
{
	write(sockfd, filebuf, filesize);
	return (0);
}

static int			send_file_size(int sockfd, int filesize)
{
	char			*size;

	size = ft_itoa(filesize);
	if (size != NULL)
	{
		send_msg(sockfd, size, ft_strlen(size));
		free(size);
	}
	else
		send_msg(sockfd, "0", 1);
	return (is_ready(sockfd));
}

int					server_get(char *file, int sockfd)
{
	int				ret;
	int				fd;
	struct stat		st;
	char			*buf;

	ret = -1;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if ((fstat(fd, &st)) != -1 && S_ISREG(st.st_mode))
		{
			if ((buf = mmap(0, st.st_size, \
				PROT_READ, MAP_PRIVATE, fd, 0)) != MAP_FAILED)
			{
				if (send_file_size(sockfd, st.st_size))
					ret = send_file_data(sockfd, buf, st.st_size);
				munmap(buf, st.st_size);
			}
		}
		close(fd);
	}
	server_get_end(sockfd, ret);
	return (0);
}
