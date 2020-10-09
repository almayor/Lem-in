/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:46:03 by unite             #+#    #+#             */
/*   Updated: 2020/09/18 05:01:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_PQ_H

# define MIN_PQ_H

# include <errno.h>
# include <sys/types.h>
# include "array.h"
# include "utils.h"

/*
** @brief A priority queue of generic keys.
** @details Implemented with a resizing array.
*/

typedef struct	s_min_pq
{
	int		*keys;
	int		*pq;
	int		*qp;
	size_t	size;
}				t_min_pq;

/*
** Initializes a new empty priority queue.
** @param type	The type of items that this queue can hold
** @return The new priority queue
** @note For this function to work, the datatype in this array must be
** comparable (i.e. implement the `cmp` function).
*/

t_min_pq	*min_pq_new(size_t max_size);

/*
** Returns the smallest key in the queue.
** @return The smallest key or `NULL` if the queue is empty.
*/

int			min_pq_peek(const t_min_pq *pq);

/*
** Removes and returns the smallest key in this queue.
** @return The smallest item in the queue, or `NULL` if the array is empty.
*/

int			*min_pq_pop(t_min_pq *pq);

/*
** Adds a copy of the specified element to the queue.
** @param data	The element to be copied
*/

void		min_pq_add(t_min_pq *pq, int i, int key);

/*
** Returns the number of keys in this queue.
** @return the number of keys in this queue.
*/

size_t		min_pq_size(const t_min_pq *pq);

/*
** Deletes this queue and free all its items and the associated data.
*/

void		min_pq_delete(t_min_pq *pq);


#endif
