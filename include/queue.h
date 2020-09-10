/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:28:22 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 23:51:11 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H

# define QUEUE_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "list.h"
# include "utils.h"

/*
** A queue of integer values
*/

typedef struct s_list	t_queue;

/*
** Frees all memory taken up by the queue
*/

void	queue_delete(t_queue *queue);

/*
** Removes the oldest value in the queue and returns it
** @return The oldest value in the queue
*/

int		queue_dequeue(t_queue *queue);

/*
** Add a value to the queue
** @param val The value to add to the queue
*/

void	queue_enqueue(t_queue *queue, int val);

/*
** Creates a new empty queue
** @return The new empty queue
*/

t_queue	*queue_new(void);

/*
** Returns the number of items in the queue
** @return The number of items in the queue
*/

size_t	queue_size(const t_queue *queue);

/*
** Returns the oldest value in the queue and keeps it from the queue
** @return The oldes value in the queue
*/

int		queue_peek(const t_queue *queue);

#endif
