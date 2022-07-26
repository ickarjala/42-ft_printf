/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:05:22 by ikarjala          #+#    #+#             */
/*   Updated: 2022/07/26 19:56:48 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bufl	*addbuf(void)
{
	return (NULL);
}

char	*bufcat(t_strinfo data)
{
	char	*str;
	t_bufl	*link;

	str = (char *)malloc(sizeof(char) * data.len);
	link = data.fst;
	while (link)
	{
		// memmove
		link = link->next;
	}
}
