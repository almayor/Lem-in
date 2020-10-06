/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:56:04 by unite             #+#    #+#             */
/*   Updated: 2020/10/06 18:46:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	link_remove(t_list *list, t_link *link)
{
	if (link->prev)
		link->prev->next = link->next;
	if (link->next)
		link->next->prev = link->prev;
	if (link == list->head)
		list->head = link->next;
	if (link == list->tail)
		list->tail = link->prev;
	free(link);
}

void		list_remove(t_list *list, int val)
{
	t_link	*link;

	link = list->head;
	while (link != NULL)
	{
		if (link->content == val)
		{
			link_remove(list, link);
			return ;
		}
		link = link->next;
	}
}
