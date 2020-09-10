/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:00:12 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 11:52:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_pop_first(t_list *list)
{
	t_link	*tmp;
	int		val;

	val = list->head->content;
	tmp = list->head;
	list->head = list->head->next;
	free(tmp);
	list->size--;
	if (list->size == 0)
		list->tail = NULL;
	else
		list->head->prev = NULL;
	return (val);
}
