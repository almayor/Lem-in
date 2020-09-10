/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:57:25 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 23:43:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H

# define ITERATOR_H

#include "list.h"
#include "utils.h"

/*
** An iterator over the contents of a list
** @remark A single list can give rise to multiple independent iterators
*/

typedef t_link	*t_iterator;

/*
** Creates an iterator from a list
** @param list The list
** @return The iterator
*/

t_iterator		*iterator_from_list(t_list *list);

/*
** Checks if an iterator has any values left
** @return `1` if the iterator is not yet empty, `0` otherwise
*/

int				iterator_has_next(const t_iterator *iter);

/*
** Returns the next value in the iterator and advances its pointer
** @return The next value in the iterator
*/

int				iterator_next(t_iterator *iter);

/*
** Frees all memory taken up by the iterator
*/

void			iterator_delete(t_iterator *iter);

#endif
