/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:48:18 by abossi            #+#    #+#             */
/*   Updated: 2016/02/25 16:17:15 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static int	ft_nextstr(const char *s, char c)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
		i++;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_nbsplit(const char *s, char c)
{
	int i;
	int offset;

	i = 1;
	offset = 0;
	while (s[offset] != '\0')
	{
		offset += ft_nextstr(s + offset, c);
		i++;
	}
	return (i);
}

static char	*ft_getstr(const char *s, char c)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s[start] == c && s[start] != '\0')
		start++;
	end = start;
	while (s[end] != c && s[end] != '\0')
		end++;
	result = (char*)malloc(sizeof(*result) * (end - start + 1));
	if (!result || start == end)
		return (NULL);
	i = start;
	while (i < end)
	{
		result[i - start] = s[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		nb;
	int		i;
	int		offset;

	if (!s)
		return (NULL);
	nb = ft_nbsplit(s, c);
	result = (char**)malloc(sizeof(*result) * nb);
	if (!result)
		return (NULL);
	i = 0;
	offset = 0;
	while (i < (nb - 1))
	{
		result[i] = ft_getstr(s + offset, c);
		offset += ft_nextstr(s + offset, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
