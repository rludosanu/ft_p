/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_dialog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/04/13 15:06:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		client_success(char *s)
{
	ft_printf("ss", s, "\n");
	return (0);
}

int		client_error(char *e)
{
	ft_printf("ss", e, "\n");
	return (-1);
}
