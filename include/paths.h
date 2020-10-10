/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:27:17 by unite             #+#    #+#             */
/*   Updated: 2020/10/10 23:52:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H

# define PATHS_H

# include <stdint.h>
# include "graph.h"
# include "list.h"
# include "utils.h"

/*
** @struct s_paths
** @brief A data structing containing the paths from `start` to `end`
** and the number of ants that each path can optimally accommodate
** @var s_paths::npaths
** @brief The total number of paths from `start` to `end`
** @var s_paths::arr
** @brief An array of paths
** @var s_paths::assignments
** @brief The number of ants that should take each path
*/

typedef struct	s_paths
{
	size_t	npaths;
	size_t	nsteps;
	t_list	**arr;
	size_t	*assignments;
}				t_paths;

/*
** Free all memory taken up by `t_paths`
*/

void			paths_delete(t_paths *paths);

t_paths			*paths_compute(t_graph *graph, size_t nants);

void			paths_assign(t_paths *paths, size_t nants);

/*
** Checks if the `i`th path can accommodate one more ant, given the optimal
** assignments of paths to ants
** @param i	The index of a path
** @return `1` if the path can accommodate, `0` otherwise
*/

int				paths_is_available(const t_paths *paths, size_t i);

/*
** Returns an iterator that an ant can use to navigate along the `i`th path,
** and decrements the path's availability
** @param i The index of a path
** @return The iterator
*/

t_link			*paths_navigate(t_paths *paths, size_t i);

/*
** Returns the length (i.e. the number of links to traverse) of the `i`th path
** @param i The index of a path
** @return The length of the path
*/

size_t			paths_length(const t_paths *paths, size_t i);

void			paths_print(const t_paths *paths, const t_graph *graph);

t_paths			*paths_from_graph(const t_graph *graph, size_t nants);

#endif
