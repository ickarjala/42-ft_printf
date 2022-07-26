/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:46:33 by ikarjala          #+#    #+#             */
/*   Updated: 2022/07/26 20:01:32 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAG_PREFIX	'%'

# define FD_IN	0
# define FD_OUT	1
# define FD_ERR	2

typedef struct s_buffer_link
{
	char			*cont;
	size_t			len;
	s_buffer_link	*next;
}	t_bufl;

typedef struct s_string_info
{
	t_bufl	*fst;
	char	*buf;
	size_t	len;
	int		evals;
}	t_strinfo;

typedef struct s_flag_info
{
	int	padding;
}	t_flaginfo;

int	ft_vprintf(const char *format, va_list ap);
int	ft_printf(const char *format, ...);

#endif
