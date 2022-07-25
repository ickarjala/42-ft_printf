/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:46:33 by ikarjala          #+#    #+#             */
/*   Updated: 2022/07/25 19:44:58 by ikarjala         ###   ########.fr       */
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

typedef struct s_string_info
{
	s_buffer_chain	*fst;
	char			*buf;
	size_t			len;
	int				evals;
}	t_strinfo;

typedef struct s_buffer_chain
{
	char			*cont;
	size_t			len;
	s_buffer_chain	*next;
}	t_bufl;

typedef struct s_flag_info
{
	int	padding;
}	t_flaginfo;

#endif
