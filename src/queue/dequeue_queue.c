/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:22:34 by kbethel           #+#    #+#             */
/*   Updated: 2020/07/16 01:04:40 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int		dequeue_queue(t_queue *queue)
{
	int		val;
	t_list	*temp;

	if (queue == NULL || queue->size < 1)
	{
		errno = EINVAL;
		return (0);
	}
	queue->size -= 1;
	val = queue->head->val;
	temp = queue->head->next;
	free(queue->head);
	queue->head = temp;
	return (val);
}
