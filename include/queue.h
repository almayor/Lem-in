/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:28:22 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 20:19:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

/*
** @struct s_queue
** A queue implemented as a doubly linked list
** @var s_queue::size
** Number of values in the queue (i.e. its size)
** @var s_queue::head
** (private member) The link with the oldest value in the queue
** @var s_queue::tail
** (private member) The link with the most recently added value in the queue
*/
typedef struct	s_queue
{
	size_t size;
	t_list *head;
	t_list *tail;
}				t_queue;

/*
** Allocates memory and initializes a queue data-structure.
** @return Pointer to the newly allocated memory or `NULL` on failure
** @exception ENOMEM	Memory allocation error
*/
t_queue			*make_queue(void);

/*
** Allocates memory for a new link to hold a value and adds this link to
** the end of the queue.
** @param queue	The queue
** @param val	The new value
** @return 0 on success, 1 on failure
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The queue is `NULL` or invalid
*/
int				enqueue_queue(t_queue *queue, int val);

/*
** Removes the oldest value in the queue (freeing memory, if necessary) and
** returns it.
** @param queue	The queue
** @return The oldest value
** @exception EINVAL	The queue is `NULL` or empty
*/
int				dequeue_queue(t_queue *queue);

/*
** Frees all memory taken by a queue or does nothing if the queue is `NULL`.
** @param queue	The queue
*/
void			free_queue(t_queue *queue);

#endif
