/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:22:34 by kbethel           #+#    #+#             */
/*   Updated: 2020/07/13 22:09:42 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int				dequeue_queue(t_queue *queue)
{
	int		val;
	t_list	*temp;

	if (queue == NULL)
	{
		errno = EINVAL;
		return (1);
	}
	queue->size -= 1;
	val = queue->head->val;
	if (queue->head->next)
	{
		temp = queue->head->next;
		queue->head->val = 0;
		queue->head->next = NULL;
		free(temp->prev);
		queue->head = temp;
	}
	else
		free_queue(queue);
	return (val);
}
