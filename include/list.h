/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:49:33 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 13:38:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "utils.h"

/*
** @struct s_link
** @brief A link in in a doubly linked list of integers
** @var s_link::content
** @brief The integer value at this link
** @var s_link::next
** @brief A pointer to the next link
** @var s_link::prev
** @brief A pointer to the previous link
*/

typedef struct	s_link
{
	int				content;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

/*
** @struct s_list
** @brief A doubly linked list of integers
** @var s_list::head
** @brief The first link in the list
** @var s_list::tail
** @brief The last link in the list
** @var s_list::size
** @brief The number of entries in the list
*/

typedef struct	s_list
{
	t_link			*head;
	t_link			*tail;
	size_t			size;
}				t_list;

/*
** Creates a new empty list
** @return The new empty list
*/

t_list			*list_new(void);

/*
** Adds an entry at the front of the list
** @param val The value to add
*/

void			list_add_first(t_list *alst, int val);

/*
** Adds an entry at the back of the list
** @param val The value to add
*/

void			list_add_last(t_list *alst, int val);

/*
** Returns the first value in the list and removes it from the list
** @return val The first value in the list
*/

int				list_pop_first(t_list *alst);

/*
** Returns the last value in the list and removes it from the list
** @return val The last value in the list
*/

int				list_pop_last(t_list *alst);

/*
** Returns the current number of entries in the list
** @return The current number of entries in the list
*/

size_t			list_size(const t_list *alst);

/*
** Frees all memory taken up by the list
*/

void			list_delete(t_list *list);

int 			list_peek_first(const t_list *list);
int 			list_peek_last(const t_list *list);
void			list_remove(t_list *list, int val);
void			list_print(const t_list *list);

#endif
