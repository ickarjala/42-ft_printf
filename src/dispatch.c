/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:38:11 by ikarjala          #+#    #+#             */
/*   Updated: 2022/07/26 20:29:22 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// PLAN OUT THE FORMAT OF THE DISPATCH TABLE!

int	parse_flag(char *format, va_list ap)
{
	if (*format == FLAG_PREFIX)
		//literal
		return (1);
	return (0);
}
