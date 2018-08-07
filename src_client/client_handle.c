/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 16:04:09 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int		client_cmd(char *cmd, char **args, int sockfd)
{
	if (!ft_strcmp("get", args[0]))
		return (client_get(cmd, args[1], sockfd));
	else if (!ft_strcmp("put", args[0]))
		return (client_put(cmd, args[1], sockfd));
	else if (!ft_strcmp("lpwd", args[0]))
		return (client_lpwd());
	else if (!ft_strcmp("pwd", args[0]))
		return (client_pwd(cmd, sockfd));
	else if (!ft_strcmp("lls", args[0]))
		return (client_lls());
	else if (!ft_strcmp("ls", args[0]))
		return (client_ls(cmd, sockfd));
	else if (!ft_strcmp("lcd", args[0]))
		return (client_lcd(args[1]));
	else if (!ft_strcmp("cd", args[0]))
		return (client_cd(cmd, args[1], sockfd));
	else if (!ft_strcmp("quit", args[0]))
		return (1);
	ft_printf("sss", "ERROR: command not found: ", cmd, "\n");
	return (0);
}

static int		client_exec(char *cmd, int sockfd)
{
	char		**args;
	int			ret;

	ret = 0;
	if (!(args = ft_strsplit(cmd, ' ')))
		return (client_error("ERROR : Unable to parse command"));
	ret = client_cmd(cmd, args, sockfd);
	ft_arrdel(&args);
	return (ret);
}

int				client_handle(int sockfd)
{
	char		buf[BUFSIZE];
	int			ret;

	ft_putstr("ftp> ");
	while ((ret = read(0, buf, BUFSIZE - 1)) > 0)
	{
		buf[ret - 1] = '\0';
		buf[ret] = '\0';
		if (!ft_strisempty(buf))
			if (client_exec(buf, sockfd) == 1)
				break ;
		ft_putstr("ftp> ");
	}
	return (0);
}
