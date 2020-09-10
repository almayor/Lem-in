/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:23:45 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 11:51:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_add_last(t_list *list, int val)
{
	t_link	*link;

	link = ft_xcalloc(sizeof(t_link), 1);
	link->content = val;
	link->prev = list->tail;
	list->size++;
	list->tail = link;
	if (list->size == 1)
		list->head = link;
	else
		list->tail->prev->next = link;
}
