/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:11:19 by kbethel           #+#    #+#             */
/*   Updated: 2020/07/16 01:04:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int		enqueue_queue(t_queue *queue, int val)
{
	t_list	*new_link;

	if (queue == NULL)
		errno = EINVAL;
	else if (!(new_link = make_list()))
		errno = ENOMEM;
	else
	{
		new_link->val = val;
		new_list->prev = queue->tail;
		if (queue->tail)
			queue->tail->next = new_link;
		else
		{
			queue->tail = new_link;
			queue->head = new_link;
		}
		queue->size += 1;
	}
	return (errno != 0);
}
