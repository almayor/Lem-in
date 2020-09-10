/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:00:19 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 11:53:03 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int list_pop_last(t_list *list)
{
	t_link	*tmp;
	int		val;

	val = list->tail->content;
	tmp = list->tail;
	list->tail = list->tail->prev;
	free(tmp);
	list->size--;
	if (list->size == 0)
		list->head = NULL;
	else
		list->tail->next = NULL;
	return (val);
}
