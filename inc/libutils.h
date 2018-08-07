/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 16:04:09 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <dirent.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbr(int n);
void		ft_puthex(unsigned int n);
size_t		ft_strlen(char *s);
char		*ft_strnew(size_t size);
void		ft_printf(char *fmt, ...);
char		**ft_strsplit(char const *s, char c);
void		ft_arrdel(char ***a);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
void		*ft_memset(void *b, int c, size_t len);
int			ft_file_exists(char *dir, char *file);
int			ft_btof(char *file, char *buf, size_t len);
char		*ft_getcwd(void);
char		*ft_itoa(int n);
char		*ft_putstrcmp(char *s1, char *s2);
int			ft_strnequ(char *s1, char *s2, int len);
int			ft_strchr(char *s, char c);
int			ft_arrlen(char **arr);
char		*ft_strcat(char *s1, char *s2);
char		*ft_strdcat(char **s1, char *s2, size_t l1, size_t l2);
int			ft_strisempty(char *s);
char		*ft_strreplace(char **s, char *r);

char		*read_msg(int fd);
void		send_msg(int fd, char *buf, size_t size);
int			is_ready(int sockfd);

#endif
