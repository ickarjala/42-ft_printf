/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:47:44 by ikarjala          #+#    #+#             */
/*   Updated: 2022/07/25 20:01:56 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_flag(char *format, va_list ap)
{
	if (*format == FLAG_PREFIX)
		//literal
		return (1);
	return (0);
}

static char	*bufcat(t_strinfo data)
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

/* iterate through format, finding % flag
 * collect flags info and pass to dispatcher
 * process variables and store a buffer for the flag output
 * append all the buffers together into 1 string, freeing memory as you go
 * write out
*/
int	printf(const char *format, ...)
{
	va_list		ap;
	t_strinfo	data;

	data = (t_strinfo){NULL, NULL, 0, 0};
	va_start(ap, format);
	while (*format)
	{
		if (*format == FLAG_PREFIX)
			parse_flag(++format, ap);
		format++;
	}
	if (data.evals)
		data.buf = bufcat(data);
	write(FD_OUT, data.buf, data.len);
	free(data.buf); // replace with protected fn
	va_end(ap);
}

// hello%%hu -> [hello]:[%hu]
