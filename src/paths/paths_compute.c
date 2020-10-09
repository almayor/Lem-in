/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:36:39 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 20:42:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

static t_paths	*paths_get_next(t_graph *graph, size_t nants)
{
	if (graph_suurballe(graph) == 0)
		return (NULL);
	return (paths_from_graph(graph, nants));
}

t_paths			*paths_compute(t_graph *graph, size_t nants)
{
	t_paths	*paths_old;
	t_paths	*paths_new;

	if (!(paths_old = paths_get_next(graph, nants)))
		terminate("ERROR");
	while ((paths_new = paths_get_next(graph, nants)) &&
			paths_new->nsteps <= paths_old->nsteps)
	{
		paths_delete(paths_old);
		paths_old = paths_new;
	}
	if (paths_new && paths_new != paths_old)
		paths_delete(paths_new);
	return (paths_old);
}
