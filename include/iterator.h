/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:57:25 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:51:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H

# define ITERATOR_H

#include "list.h"
#include "utils.h"

typedef struct	s_iterator
{
	t_link	*pointer;
}				t_iterator;

t_iterator		*iterator_from_list(t_list *list);
int				iterator_has_next(const t_iterator *iter);
int				iterator_next(t_iterator *iter);
void			iterator_delete(t_iterator *iter);

#endif
