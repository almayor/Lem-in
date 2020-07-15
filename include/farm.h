/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:54:01 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 23:27:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

#include <errno.h>
#include "libftprintfgnl.h"
#include "list.h"
#include "map.h"

/*
** @struct s_farm
** @brief An ant farm
** @details A data structure representing the paths and the position on them
** that each ant takes
** @var s_farm::n_ants
** Number of ants
** @var s_farm::ants
** A list of position on each ant's remaining path.
** @details Example: If the first ant's path is 1->2->3->4 and the ant is
** currently at vertex 2, then ants[0] points at the path's link holding the
** vertex 2. Please note that several ants' positions can point to different
** links in the same linked list. Therefore, as ants progress along their paths
** no memory should be freed or allocated.
*/
typedef struct	s_farm
{
	int		n_ants;
	t_list	**ants;
}				t_farm;

/*
** Allocates memory and initializes a data structure representing an ant farm.
** @param n_ants The number of ants
** @return Pointer to the newly allocated memory or `NULL` on failure.
** @exception ENOMEM	Memory allocation error
*/
t_farm			*make_farm(int n_ants);

/*
** Run the farm with the given paths. For each ant, allocate a path and run
** it along it. If several ants share a path (in the cases where there are
** fewer paths than ants), wait until the ant in front has moved ahead before
** putting the next ant on this path at the start.
** Print out each ant's position at
** every step, given a map from vertex id's to vertex names;
** @param farm	The ant farm
** @param paths	An array with all existing paths.
** @param n_paths The number of paths.
** @param vertex_names A map from vertex id's to vertex names
*/
void			run_farm(t_farm *farm, t_list **paths, int n_paths,
						t_map *vertex_names);

/*
** Frees all memory taken by an ant farm or does nothing if the farm is `NULL`.
*/
void			free_farm(t_farm *farm);

#endif
