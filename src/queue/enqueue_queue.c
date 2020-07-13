/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:11:19 by kbethel           #+#    #+#             */
/*   Updated: 2020/07/13 21:44:15 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int				enqueue_queue(t_queue *queue, int val)
{
	t_list	*new_link;

	if (queue == NULL)
	{
		errno = EINVAL;
		return (1);
	}
	if (!(new_link = make_list()))
	{
		errno = ENOMEM;
		return (1);
	}
	queue->size += 1;
	if (queue->head == NULL)
	{
		queue->head = new_link;
		queue->tail = queue->head;
	}
	else
	{
		queue->tail->next = new_link;
		queue->tail->next->val = val;
		queue->tail->next->prev = queue->tail;
		queue->tail = queue->tail->next;
	}
	return (0);
}
