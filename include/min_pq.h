/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:46:03 by unite             #+#    #+#             */
/*   Updated: 2020/10/11 11:26:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_PQ_H

# define MIN_PQ_H

# include <errno.h>
# include <sys/types.h>
# include "array.h"
# include "utils.h"

/*
** @brief A priority queue of fixed size.
** @details It supports the usual insert and delete-the-minimum operations
** as well as change-the-value methods. Each value in the queue is associated
** with an integer handle.
** @note Implemented as a binary heap along with arrays to
** associate values with integers in the given range.
*/

typedef struct	s_min_pq
{
	int		*vals;
	int		*pq;
	int		*qp;
	size_t	size;
}				t_min_pq;

/*
** Initializes a new empty priority queue.
** @param max_size	Maximum number of elements that the queue can hold.
** @return The new priority queue
*/

t_min_pq		*min_pq_new(size_t max_size);

/*
** Returns the integer associated with the smallest value in the queue
** without removing it.
** @return The integer associated with the smallest value.
*/

int				min_pq_peek(const t_min_pq *pq);

/*
** Removes and returns the integer associated with the smallest value
** in the queue.
** @return The integer associated with the smallest value.
*/

int				min_pq_pop(t_min_pq *pq);

/*
** Adds an integer an its associated value to the queue.
** @param i	The integer
** @param val Its associated value
*/

void			min_pq_add(t_min_pq *pq, int i, int val);

/*
** Returns the number of elements in this queue.
** @return the number of elements in this queue.
*/

size_t			min_pq_size(const t_min_pq *pq);

/*
** Deletes this queue and free all its associated data.
*/

void			min_pq_delete(t_min_pq *pq);

/*
** Removes all element from the queue without freeing it
*/

void			min_pq_empty(t_min_pq *pq);

/*
** Changes the value associated with a given integer
** @param i The integer
** @param val The new value associated with the integer
*/

void			min_pq_edit(t_min_pq *pq, int i, int val);

/*
** Checks that a given integer is contained in the priority queue
** @param i The integer
** @return `1` if the integer is in the queue, `0` otherwise
*/

int				min_pq_contains(const t_min_pq *pq, int i);

/*
** A convenience function that adds an integer-value pair to the queue,
** if it's not already contained in the queue, or reassociates the integer
** with a new value otherwise.
** param i The integer
** param val Its associated value
*/

void			min_pq_insert(t_min_pq *pq, int i, int val);

void			min_pq_swap(t_min_pq *pq, size_t i, size_t j);
void			min_pq_sink(t_min_pq *pq, size_t k);
void			min_pq_swim(t_min_pq *pq, size_t k);

#endif
