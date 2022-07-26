/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:47:44 by ikarjala          #+#    #+#             */
/*   Updated: 2022/07/26 19:38:27 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* iterate through format, finding % flag
 * collect flags info and pass to dispatcher
 * process variables and store a buffer for the flag output
 * append all the buffers together into 1 string, freeing memory as you go
 * write out
*/
int	ft_vprintf(const char *format, va_list ap)
{
	t_strinfo	data;

	data = (t_strinfo){NULL, NULL, 0, 0};
	while (*format)
	{
		if (*format == FLAG_PREFIX)
			parse_flag(++format, ap);
		format++;
	}
	va_end(ap);
	if (data.evals)
		data.buf = bufcat(data);
	write(FD_OUT, data.buf, data.len);
	free(data.buf); // replace with protected fn
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vprintf(format, ap));
}
