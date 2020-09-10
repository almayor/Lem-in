/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:36:39 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 16:56:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

static size_t	paths_assign(const t_paths *paths, size_t nants, size_t nused,
							size_t *assigments_new)
{
	size_t	nsteps_new;
	size_t	i;

	i = 0;
	while (i + 1 < nused)
	{
		nants -= (paths_length(paths, nused - 1) - paths_length(paths, i));
		assigments_new[i] = (paths_length(paths, nused - 1) -
							 paths_length(paths, i));
		i++;
	}
	i = 0;
	while (i < nused)
	{
		assigments_new[i] += nants / nused;
		if (i < nants % nused)
			assigments_new[i] += 1;
		i++;
	}
	nsteps_new = paths_length(paths, 0) + assigments_new[0] - 1;
	return (nsteps_new);
}

static void 	paths_reassign(t_paths *paths, size_t *assigments_new)
{
	size_t i;

	i = 0;
	while (i < paths->npaths)
	{
		paths->assignments[i] = assigments_new[i];
		i++;
	}
}

static void		paths_filter(t_paths *paths, size_t nants)
{
	size_t	i;
	size_t	nsteps_old;
	size_t	nsteps_new;
	size_t	*assigments_new;

	assigments_new = ft_xcalloc(sizeof(size_t), nants);
	nsteps_old = SIZE_MAX;
	i = 1;
	while (i <= paths->npaths)
	{
		nsteps_new = paths_assign(paths, nants, i, assigments_new);
		if (nsteps_new >= nsteps_old)
			break ;
		paths_reassign(paths, assigments_new);
		nsteps_old = nsteps_new;
		i++;
	}
	free(assigments_new);
}

t_paths			*paths_get(t_graph *graph, size_t nants)
{
	t_paths	*paths;

	paths = ft_xcalloc(sizeof(t_paths), 1);
	paths->npaths = graph_edkarp(graph, &(paths->arr), nants);
	if (paths->npaths < 1)
		terminate(ERR_INVALID_INPUT);
	paths->assignments = ft_xcalloc(sizeof(size_t), nants);
	paths_filter(paths, nants);
	return (paths);
}
