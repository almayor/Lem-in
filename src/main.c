/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:27:50 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 19:44:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfgnl.h"
#include "graph.h"
#include "list.h"
#include "paths.h"
#include "parse.h"
#include "stdin.h"

static size_t	step_once(t_iterator **ants, size_t nants,
								const t_graph *graph)
{
	size_t	nants_moved;
	size_t	i;

	nants_moved = 0;
	i = 0;
	while (i < nants)
	{
		if (iterator_has_next(ants[i]))
		{
			ft_printf("%cL%i-%s",
				nants_moved > 0 ? ' ' : '\n',
				i + 1,
				graph_id2name(graph, iterator_next(ants[i])));
			nants_moved++;
		}
		i++;
	}
	return (nants_moved);
}

static void		cycle_to_finish(t_iterator **ants, size_t nants,
								const t_graph *graph)
{
	while (step_once(ants, nants, graph) > 0)
		continue ;
	ft_putchar('\n');
}

static void		lemin(t_paths *paths, size_t nants, const t_graph *graph)
{
	t_iterator	**ants;
	size_t		nants_active;
	size_t		i;

	ants = ft_xcalloc(sizeof(t_iterator *), nants);
	nants_active = 0;
	while (nants_active < nants)
	{
		i = 0;
		while (i < paths->npaths && nants_active < nants)
		{
			if (paths_is_available(paths, i))
				ants[nants_active++] = paths_navigate(paths, i);
			i++;
		}
		step_once(ants, nants, graph);
	}
	cycle_to_finish(ants, nants, graph);
	while (nants_active > 0)
		iterator_delete(ants[--nants_active]);
	free(ants);
}

int 			main(void)
{
	t_stdin	*in;
	size_t	nants;
	t_graph	*graph;
	t_paths	*paths;
	
	in = stdin_new();
	nants = parse_nants(in);
	graph = parse_rooms(in);
	parse_links(in, graph);
	paths = paths_get(graph, nants);
	lemin(paths, nants, graph);
	stdin_delete(in);
	graph_delete(graph);
	paths_delete(paths);
}
