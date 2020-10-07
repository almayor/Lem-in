/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:36:39 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 16:20:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

static t_paths	*paths_get(t_graph *graph, size_t nants)
{
	t_paths		*paths;
	static int	npaths;

	paths = ft_xcalloc(sizeof(t_paths), 1);
	paths->npaths = ++npaths;
	if (!(paths->arr = graph_suurballe(graph)))
	{
		free(paths);
		return (NULL);
	}
	paths->assignments = ft_xcalloc(sizeof(size_t), nants);
	paths_assign(paths, nants);
	return (paths);
}

t_paths		*paths_compute(t_graph *graph, size_t nants)
{
	t_paths	*paths_old;
	t_paths	*paths_new;

	if (!(paths_old = paths_get(graph, nants)))
		terminate("ERROR");
	while ((paths_new = paths_get(graph, nants)) &&
		paths_new->nsteps < paths_old->nsteps)
	//int i = 0;
	//while (i++ < 10 && (paths_new = paths_get(graph, nants)))
	{
			paths_delete(paths_old);
			paths_old = paths_new;
	}
	if (paths_new && paths_new != paths_old)
		paths_delete(paths_new);
	return (paths_old);
}
