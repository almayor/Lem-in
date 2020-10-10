/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:42:02 by unite             #+#    #+#             */
/*   Updated: 2020/10/08 21:26:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdin.h"

static void	get_line(t_stdin *in)
{
	in->line = in->ptr;
	if (!(in->ptr = ft_strchr(in->ptr, '\n')))
		terminate(ERR_INVALID_INPUT);
	*(in->ptr) = '\0';
}

const char	*stdin_next(t_stdin *in)
{
	ssize_t		ret;
	size_t 		carryover;

	if (in->end)
		return (NULL);
	in->ptr++;
	if (ft_strchr(in->ptr, '\n') == NULL)
	{
		carryover = ft_strlen(in->ptr);
		ft_memmove(in->buffer, in->ptr, carryover + 1);
		in->ptr = in->buffer;
		ret = read(0, in->buffer + carryover, BUFFER_SIZE - carryover);
		if (ret < 0)
			terminate(ERR_STDIN);
		if (ret == 0)
		{
			in->line = in->ptr;
			in->end = 1;
			return (in->line);
		}
		in->buffer[carryover + ret] = '\0';
		write(1, in->buffer + carryover, ret);
	}
	get_line(in);
	return (in->line);
}
