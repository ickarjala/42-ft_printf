/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:47:44 by ikarjala          #+#    #+#             */
/*   Updated: 2022/06/30 17:35:04 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flag(char *format, va_list *ap)
{
	
}

int	printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == FLAG_PREFIX)

		format++;
	}
	va_end(ap);
}
