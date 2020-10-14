/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:15:58 by user              #+#    #+#             */
/*   Updated: 2020/10/14 23:42:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

static void		paths_insert_next(t_paths *paths, int j)
{
	t_list	*tmp;

	while (j > 0)
	{
		if (paths->arr[j]->size < paths->arr[j - 1]->size)
		{
			tmp = paths->arr[j];
			paths->arr[j] = paths->arr[j - 1];
			paths->arr[j - 1] = tmp;
		}
		else
			break ;
		j--;
	}
}

/*
** Sorts the paths by their length in the ascending order. A necessary step
** before assignment.
*/

static void		paths_insertion_sort(t_paths *paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < paths->npaths - 1)
	{
		if (paths->arr[i]->size > paths->arr[i + 1]->size)
			paths_insert_next(paths, i + 1);
		i++;
	}
}

/*
** Computes the best assignment (one that would result in the fewest steps)
** of `nants` by using only the first `nused` paths and ignoring the rest
** @param[in] nants The total number of ants
** @param[in] nused The number of best paths to use
** @param[out] assignment_new The best assignment satisfying these conditions
** @return The number of steps in this assignment
*/

static size_t	paths_assign_once(const t_paths *paths, size_t nants,
								size_t nused, size_t *assigments_new)
{
	size_t	nsteps_new;
	size_t	i;

	i = 0;
	while (i + 1 < nused)
	{
		nants -= (paths_length(paths, nused - 1) - paths_length(paths, i));
		if (paths_length(paths, nused - 1) > paths_length(paths, i))
			assigments_new[i] = paths_length(paths, nused - 1) -
								paths_length(paths, i);
		else
			assigments_new[i] = 0;
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

/*
** Replace current assignments with new ones
** @param assignments_new New assignments
*/

static void		paths_reassign(t_paths *paths, size_t *assigments_new)
{
	size_t i;

	i = 0;
	while (i < paths->npaths)
	{
		paths->assignments[i] = assigments_new[i];
		i++;
	}
}

void			paths_assign(t_paths *paths, size_t nants)
{
	size_t	i;
	size_t	nsteps_old;
	size_t	nsteps_new;
	size_t	*assigments_new;

	paths_insertion_sort(paths);
	assigments_new = ft_xcalloc(sizeof(size_t), nants);
	nsteps_old = SIZE_MAX;
	i = 1;
	while (i <= paths->npaths && nsteps_old > list_size(paths->arr[i - 1]))
	{
		nsteps_new = paths_assign_once(paths, nants, i, assigments_new);
		paths_reassign(paths, assigments_new);
		nsteps_old = nsteps_new;
		i++;
	}
	free(assigments_new);
	paths->nsteps = nsteps_old;
}
