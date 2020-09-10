/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:23:45 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 11:50:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_add_first(t_list *list, int val)
{
	t_link	*link;

	link = ft_xcalloc(sizeof(t_link), 1);
	link->content = val;
	link->next = list->head;
	list->size++;
	list->head = link;
	if (list->size == 1)
		list->tail = link;
	else
		list->head->next->prev = list->head;
}
