/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:33:28 by unite             #+#    #+#             */
/*   Updated: 2020/10/08 21:20:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdin.h"

t_stdin	*stdin_new(void)
{
	t_stdin	*in;
	ssize_t ret;

	in = ft_xcalloc(sizeof(t_stdin), 1);
	in->ptr = in->buffer;
	return (in);
}
