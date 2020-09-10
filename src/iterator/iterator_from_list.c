/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_from_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:59:21 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 23:16:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.h"

t_iterator	*iterator_from_list(t_list *list)
{
	t_iterator	*iter;

	iter = ft_xmalloc(sizeof(t_iterator));
	*iter = list->head;
	return (iter);
}
