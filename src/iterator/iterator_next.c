/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:00:59 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:52:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.h"

int	iterator_next(t_iterator *iter)
{
	int	val;

	val = iter->pointer->content;
	iter->pointer = iter->pointer->next;
	return (val);
}
