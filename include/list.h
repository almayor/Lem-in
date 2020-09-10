/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:49:33 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:26:27 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "utils.h"

typedef struct		s_link
{
	int				content;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_list
{
	t_link			*head;
	t_link			*tail;
	size_t			size;
}					t_list;

t_list			*list_new(void);
void			list_add_first(t_list *alst, int val);
void			list_add_last(t_list *alst, int val);
int				list_pop_first(t_list *alst);
int				list_pop_last(t_list *alst);
size_t			list_size(const t_list *alst);
void			list_delete(t_list *list);

#endif
