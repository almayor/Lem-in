/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:49:33 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 20:22:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <errno.h>
#include "libftprintfgnl.h"

/*
** @struct s_list
** Represents a doubly-linked list
** @var s_list::next
** Next link in the list
** @var s_list::prev
** Previous link in the list
** @var s_list::val
** Value held by this link
*/
typedef struct	s_list
{
	t_list	*next;
	t_list	*prev;
	int		val;
}				t_list;

/*
** Allocates memory and initializes a list data-structure.
** @return Pointer to the newly allocated memory of `NULL` on failure
** @exception ENOMEM	Memory allocation error
*/
t_list			*make_list(void);

/*
** Allocates memory for a new link to hold a value and adds this link at the
** beginning of the list.
** @param list	The list
** @param val	The new value
** @return 0 on success, 1 on failure
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The list is `NULL` of invalid
*/
t_list			*add_list(t_list *list, int val);

/*
** Frees all memory taken by a list or does nothing if the list is `NULL`.
** @param list	The list
*/
void			free_list(t_list *list);

#endif
