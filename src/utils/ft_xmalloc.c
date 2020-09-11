/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:38:47 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 03:33:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Replicates behaviour of `malloc` from `libc`, but fails on
** memory allocation errors.
*/

void	*ft_xmalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem && !size)
		terminate(ERR_NO_MEMORY);
	return (mem);
}
