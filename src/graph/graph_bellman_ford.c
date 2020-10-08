/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bellman_ford.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:49:47 by user              #+#    #+#             */
/*   Updated: 2020/10/08 17:43:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <limits.h>
#include <assert.h>

static void	relax_edges(t_graph *graph)
{
	int			v;
	int			w;
	t_iterator	*iter;

	v = 0;
	while (v < graph->nnodes)
	{
		iter = iterator_from_list(graph->nodes[v]->edges);
		while (iterator_has_next(iter))
		{
			w = iterator_next(iter);
			graph_relax_edge(graph, v, w);
		}
		iterator_delete(iter);
		v++;
	}
}

void graph_bellman_ford(t_graph *graph)
{
	int	i;

	graph_reset(graph);
	i = 0;
	while (i < graph->nnodes - 1)
	{
		relax_edges(graph);
		i++;
	}
}
