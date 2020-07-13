/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:05:14 by kbethel           #+#    #+#             */
/*   Updated: 2020/07/13 21:27:24 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void			free_queue(t_queue *queue)
{
	if (!queue)
		return ;
	queue->size = 0;
	free_list(queue->head);
	free(queue);
}
