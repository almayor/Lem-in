/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:27:17 by unite             #+#    #+#             */
/*   Updated: 2020/10/11 12:58:03 by user             ###   ########.fr       */
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
** @brief A data structing containing the paths in the graph
** @details A data structing containing the paths in the graph
** from `start` to `end` and assignments of `nants` ants among them
** @var s_paths::nsteps
** @brief The number of steps its would take to walk `nants` ants from
** `start` to `end` given these paths and assignments.
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
** Computes the best paths given a graph and `nants` ants.
** @param graph The graph
** @param nants The number of ants
** @return The paths
*/

t_paths			*paths_compute(t_graph *graph, size_t nants);

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

/*
** Calculates the best assignment of `nants` ants over the paths
** @param nants The total number of ants
*/

void			paths_assign(t_paths *paths, size_t nants);

/*
** Gets all paths from the start to the end that currently exist in the graph
** and calculates the best assignment of `nants` ants over these paths
** @param graph The graph
** @param nants The total number of ants
** @return The paths
*/

t_paths			*paths_from_graph(const t_graph *graph, size_t nants);

/*
** Prints the paths
** @param paths The paths
** @graph graph The associated graph
** @note Function used for debugging
*/

void			paths_print(const t_paths *paths, const t_graph *graph);

/*
** Free all memory taken up by `t_paths`
*/

void			paths_delete(t_paths *paths);

#endif
