/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:27:17 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:36:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H

# define PATHS_H

# include "graph.h"
# include "iterator.h"
# include "list.h"
# include "utils.h"

typedef struct	s_paths
{
	size_t	npaths;
	t_list	**arr;
	size_t	*assignments;
}				t_paths;

void			paths_delete(t_paths *paths);
t_paths			*paths_get(t_graph *graph, size_t nants);
int				paths_is_available(const t_paths *paths, size_t i);
t_iterator		*paths_navigate(t_paths *paths, size_t i);
size_t			paths_length(const t_paths *paths, size_t i);

#endif
