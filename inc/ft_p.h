/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/05/09 18:27:35 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include "libutils.h"

# define BUFSIZE 1024

typedef struct		s_server
{
	int				sockfd;
	char			*rootdir;
}					t_server;

typedef struct		s_client
{
	int				sockfd;
	char			*currdir;
}					t_client;

/*
** Client
*/

int					client_success(char *s);
int					client_error(char *e);
int					client_handle(int sockfd);
int					client_get(char *cmd, char *file, int sockfd);
int					client_put(char *cmd, char *file, int sockfd);
int					client_lpwd(void);
int					client_lcd(char *path);
int					client_lls(void);
int					client_pwd(char *cmd, int sockfd);
int					client_ls(char *cmd, int sockfd);
int					client_cd(char *cmd, char *path, int sockfd);

/*
** Server
*/

int					server_error(char *error);
int					server_handle(t_server *srv);
int					server_get(char *file, int sockfd);
int					server_put(char *file, int sockfd);
int					server_pwd(t_server *srv, t_client *clt);
int					server_ls(int sockfd);
int					server_cd(char *path, t_server *srv, t_client **clt);
t_client			*clt_create(int sockfd, char *rootdir);
void				clt_delete(t_client **clt);

#endif
